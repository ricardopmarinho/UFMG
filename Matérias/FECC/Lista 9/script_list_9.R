library(imager)
setwd("UFMG/Matérias/FECC/Lista 9/")
im<-read.csv("zip.train",header = FALSE,sep="")
mat_dig<-list()
for(i in 1:10){
  mat_dig[[i]]<-list()
}
for(i in 1:nrow(im)){
  dig<-im[i,1]+1
  pixels<-im[i,2:ncol(im)]
  ind<-length(mat_dig[[dig]])+1
  mat_dig[[dig]][[ind]]<-matrix(pixels,ncol = 16,nrow = 16)
}
maior<-0
for(i in 1:length(mat_dig[])){
  if(length(mat_dig[[i]])>maior){
    maior<-length(mat_dig[[i]])
  }
}
mat_pixels<-matrix(0,nrow = 16*16,ncol=nrow(im))
for(i in 1:10){
  for(j in 1:length(mat_dig[[i]])){
    mat_pixels[,j+(i-1)*length(mat_dig[[i]])] = stack(as.data.frame(mat_dig[[i]][[j]]))[,1]
  }
}
set.seed(123)
ind=sample(10,1:maior,replace = T)
indcol=ind+((1:10)-1)*maior
mat_test=mat_pixels[,indcol]
mat_pixels=mat_pixels[,-indcol]
mat_media=apply(mat_pixels, 1, mean)
mat_centrada=mat_pixels-mat_media
pca_pixels=prcomp(t(mat_centrada))
autovalores=(pca_pixels$sdev)^2
autovetores = pca_pixels$rot[ , 1:20]
auto_face=list()
for(i in 1:20){
  auto_face[[i]]=as.cimg(pca_pixels$rot[,i],x=16,y=16)
}
coef = t(autovetores) %*% (mat_test - mat_media)
coef_treino = t(autovetores) %*% (mat_pixels - mat_media)
coefmedio = matrix(0, ncol=10, nrow=20)
for(i in 1:10){
  coefmedio[,i] = apply(coef_treino[ ,(1+(i-1)*10) : (i*10)], 1, mean)
}
indproximo = numeric()
for(j in 1:10){
  indproximo[j] = which.min( apply((coefmedio - coef[,j])^2, 2, mean) )
}