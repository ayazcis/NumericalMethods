#include <stdio.h>
#include <math.h>
#define n 100
int fonksiyonal();
void bisection();
double fonksonuc(double x,int derece,double dizi[100]);
void regulafalsi();
double turevsonuc(double dizi[n],int derece,double x);
void fonkkatsayi(double dizi[n],int derece);
void newtonraphson();
void matrisal(double matris[n][n],int derece);
void inversematrix();
void gausskatsayial(double matris[n][n],int denklem,int bilinmeyen);
void gausselemination();
int main(){
	int choice;
	
	do{
		printf("\nQuit:0\nBisection:1\nRegula-Falsi:2\nNewton Raphson:3\nInverse Matrix:4\nGauss Elimination:5\nGauss-Seidel:6\nNumerical Differentiation:7\nSimpson's Rule:8\nTrapezodial Rule:9\nGregory Newton: 10\nChoice:");
		scanf("%d",&choice);
		if(choice==1){
			bisection();
		}
		else if(choice==2){
			regulafalsi();
		}
		else if(choice==3){
			newtonraphson();
		}
		else if(choice==4){
			inversematrix();
		}
		gausselemination();

		
		
		
		
		
	}while(choice != 0);
	
	
	
	
	
	
	
	
	return 0;
}
int fonksiyonderece(){
	int derece;
	printf("\nFonksiyonunuzun derecesi kac?");
	scanf("%d", &derece);
	return derece;
}
void fonkkatsayi(double dizi[n],int derece){
	int i;	
	for(i=0;i<=derece;i++){
		printf("x^%d dereceli elemanin katsayisi kac?", i);
		scanf("%lf",&dizi[i]);
	}
}
void bisection(){
	int derece,bitir;
	double kucuk,buyuk,dizi[n],tmp,hata,kucuksonuc,buyuksonuc;
	derece = fonksiyonderece();
	fonkkatsayi(dizi,derece);
	do{
		do{
		printf("Kok araligini once kucuk sonra buyuk olmak uzere giriniz.");
		scanf("%lf %lf",&kucuk,&buyuk);
		kucuksonuc =fonksonuc(kucuk,derece,dizi);
		buyuksonuc = fonksonuc(buyuk,derece,dizi);
		if( kucuksonuc*buyuksonuc>0){
			printf("\nBu aralikta kok yok tekrar giriniz.");
		}
		}while(kucuksonuc*buyuksonuc>0);
		printf("\nIstenilen min hatayi giriniz");
		scanf("%lf",&hata);
		if(fonksonuc(kucuk,derece,dizi)!=0 || fonksonuc(buyuk,derece,dizi)!=0){
			tmp = (kucuk+buyuk)/2;
			while(fabs(fonksonuc(tmp,derece,dizi))>hata){
				tmp = (kucuk+buyuk)/2;
				if(fonksonuc(tmp,derece,dizi)*fonksonuc(kucuk,derece,dizi)<=0){
					buyuk=tmp;
				}
				if(fonksonuc(tmp,derece,dizi)*fonksonuc(buyuk,derece,dizi)<=0){
					kucuk=tmp;
				}
			}
		}
		
		if(fonksonuc(kucuk,derece,dizi)==0 & fonksonuc(buyuk,derece,dizi)==0){
			printf("\nSonuc: %f ve %f \n",kucuk,buyuk);
		}
		else{
			printf("\nSonuc: %f\n",tmp);
		}
		printf("Baska bir aralik girmek icin 1'e bitirmek icin 0'a basiniz.");
		scanf("%d",&bitir);
	}while(bitir!=0);
	
	
	
}
double fonksonuc(double x,int derece,double dizi[100]){
	double sonuc=0.0;
	int i;
	for(i=0;i<=derece;i++){
		sonuc += dizi[i]*pow(x,i);
	}

	return sonuc;
}
void regulafalsi(){
	int derece,bitir;
	double kucuk,buyuk,dizi[n],tmp,hata,kucuksonuc,buyuksonuc;
	derece = fonksiyonderece();
	fonkkatsayi(dizi,derece);
	do{
		do{
		printf("Kok araligini once kucuk sonra buyuk olmak uzere giriniz.");
		scanf("%lf %lf",&kucuk,&buyuk);
		kucuksonuc =fonksonuc(kucuk,derece,dizi);
		buyuksonuc = fonksonuc(buyuk,derece,dizi);
		if( kucuksonuc*buyuksonuc>0){
			printf("\nBu aralikta kok yok tekrar giriniz.");
		}
		}while(kucuksonuc*buyuksonuc>0);
		printf("\nIstenilen min hatayi giriniz");
		scanf("%lf",&hata);
		tmp = ((buyuk*fonksonuc(kucuk,derece,dizi))-(kucuk*fonksonuc(buyuk,derece,dizi)))/(fonksonuc(kucuk,derece,dizi)-fonksonuc(buyuk,derece,dizi));
		if(fonksonuc(kucuk,derece,dizi)!=0 || fonksonuc(buyuk,derece,dizi)!=0){
			while(fabs(fonksonuc(tmp,derece,dizi))>hata){
				tmp = ((buyuk*fonksonuc(kucuk,derece,dizi))-(kucuk*fonksonuc(buyuk,derece,dizi)))/(fonksonuc(kucuk,derece,dizi)-fonksonuc(buyuk,derece,dizi));
				if(fonksonuc(tmp,derece,dizi)*fonksonuc(kucuk,derece,dizi)<=0){
					buyuk=tmp;
				}
				if(fonksonuc(tmp,derece,dizi)*fonksonuc(buyuk,derece,dizi)<=0){
					kucuk=tmp;
				}
			}
		}
		
		if(fonksonuc(kucuk,derece,dizi)==0 & fonksonuc(buyuk,derece,dizi)==0){
			printf("\nSonuc: %f ve %f \n",kucuk,buyuk);
		}
		else{
			printf("\nSonuc: %f\n",tmp);
		}
		printf("Baska bir aralik girmek icin 1'e bitirmek icin 0'a basiniz.");
		scanf("%d",&bitir);
	}while(bitir!=0);
}
	
double turevsonuc(double dizi[n],int derece,double x){
	int i;
	double sonuc=0.0;
	for(i=1;i<=derece;i++){
		sonuc+= i*pow(x,(i-1))*dizi[i];
	}
	return sonuc;
	
}
void newtonraphson(){
	double kucuk,buyuk,dizi[n],kucuksonuc,buyuksonuc,hata,sonuc,turev,temp,baslangic;
	int derece;
	derece = fonksiyonderece();
	fonkkatsayi(dizi,derece);
	printf("Kok araligini once kucuk sonra buyuk olmak uzere giriniz.");
	scanf("%lf %lf",&kucuk,&buyuk);
	baslangic=kucuk;
	kucuksonuc =fonksonuc(kucuk,derece,dizi);
	buyuksonuc = fonksonuc(buyuk,derece,dizi);
	printf("\nIstenilen min hatayi giriniz");
	scanf("%lf",&hata);
	if(fonksonuc(kucuk,derece,dizi)==0 && fonksonuc(buyuk,derece,dizi)==0){
		printf("\nSonuc: %lf ve %lf \n",kucuk,buyuk);
	}
	else if(fonksonuc(kucuk,derece,dizi)==0){
		printf("\nSonuc: %lf \n",kucuk);
	}
	else if(fonksonuc(buyuk,derece,dizi)==0){
		printf("\nSonuc: %lf \n",buyuk);
	}

	else{
		do{
			temp=baslangic;
			sonuc=fonksonuc(temp,derece,dizi);
			turev=turevsonuc(dizi,derece,temp);
			baslangic = temp - (sonuc/turev);
		}while(fabs(baslangic-temp)>hata && kucuk<baslangic && buyuk>baslangic);
		
		if(fabs(baslangic-temp)<hata){
			printf("\nSonuc: %lf\n",baslangic);
		}
		else{
			printf("Iraksadi\n");
		}
	}
}
void matrisal(double matris[n][n],int derece){
	int i,j;
	for(i=0;i<derece;i++){
		for(j=0;j<derece;j++){
			printf("\nmatrisin %d. satirinin %d. elemanini giriniz. ",i,j);
			scanf("%lf",&matris[i][j]);
		}
	}
}
void inversematrix(){
	double matris[n][n],det=0.0,birim[n][n],katsayi;
	int boyut,i=0,j,k,sifir,detsifir=0;
	printf("\nMatrisin boyutunu giriniz");
	scanf("%d",&boyut);
	matrisal(matris,boyut);
	while(detsifir==0 && i<boyut){
		sifir=0;
		for(j=0;j<boyut;j++){
			if(matris[j][i]==0){
				sifir++;
			}
		}
		if(sifir==boyut){
			detsifir=1;
		}
		i++;
	}
	if(boyut==1){
		printf("\nMatrisin tersi: %lf",1/matris[0][0]);
	}
	else if(detsifir==1){
		printf("determinant = 0, matrisin tersi yok.");
	}
	else{
		for(i=0;i<boyut;i++){
			for(j=0;j<boyut;j++){
				if(i==j){
					birim[i][j]=1;
				}
				else{
					birim[i][j]=0;
				}
			}
		}
		for(i=0;i<boyut-1;i++){
			//matrisin köşegenleri 0 olmamasını sağlamak
    		int maxIndex = i;
    		double maxVal = matris[i][i];
   			for (int p = i + 1; p < boyut; p++) {
        		if (fabs(matris[p][i]) > fabs(maxVal)) {
            		maxVal = matris[p][i];
            		maxIndex = p;
        		}
    		}
    		if (maxIndex != i) {
        		// matris satırlarını değiştirme
        		for (int p = 0; p < boyut; p++) {
            		double temp = matris[i][p];
            		matris[i][p] = matris[maxIndex][p];
            		matris[maxIndex][p] = temp;
            		temp = birim[i][p];
            		birim[i][p] = birim[maxIndex][p];
            		birim[maxIndex][p] = temp;
        		}
    		}
			for(j=i+1;j<boyut;j++){
				katsayi = -matris[j][i]/matris[i][i];
				for(k=0;k<boyut;k++){
					matris[j][k] += matris[i][k]*katsayi;
					birim[j][k] +=birim[i][k]*katsayi;
				}
			}
		
		}
		det = matris[boyut-1][boyut-1]*matris[boyut-2][boyut-2];
		for(i=boyut-3;i>-1;i--){
			det = matris[i][i]*pow(-1,(i+i))*det;
		}
		for(i=0;i<boyut;i++){
			for (k = 0; k < boyut; k++) {
  		  		birim[i][k] /= matris[i][i];
  			}
		}
		if(det==0){
			printf("determinant = 0, matrisin tersi yok.");
		}
		else{
			printf("\nGirilen matrisin tersi:\n");
			for(i=0;i<boyut;i++){
				for(j=0;j<boyut;j++){
					printf(" %lf |",birim[i][j]);
				}
				printf("\n");
			}
		}
	}
	
	
	
}
void gausskatsayial(double matris[n][n],int denklem,int bilinmeyen){
	int i,j;
	for(i=1;i<=denklem;i++){
		for(j=1;j<=bilinmeyen;j++){
			printf("\n%d. denklemdeki %d. bilinmeyenin katsayisi: ",i,j);
			scanf("%lf",&matris[i-1][j-1]);
		}
	}
}
void gausselemination(){
	int denklem,p,k,maxIndex,i,j;
	double katsayimatris[n][n],katsayi,sonuc[n],deger[n],tmp=0,maxVal,temp;
	printf("\nKac tane denklem gireceksiniz? (Bilinmeyen sayisiyla esit olmali) ");
	scanf("%d",&denklem);
	printf("\nDenklemlerin katsayilar matrisini giriniz. ");
	gausskatsayial(katsayimatris,denklem,denklem);
	printf("\nDenklemlerin sonuclarini giriniz: ");
	for(i=0;i<denklem;i++){
		printf("\n%d. denklemin sonucu: ",i+1);
		scanf("%lf",&sonuc[i]);
	}
	for(i=0;i<denklem-1;i++){
			//matrisin köşegenleri 0 olmamasını sağlamak
    		int maxIndex = i;
    		double maxVal = katsayimatris[i][i];
   			for (int p = i + 1; p < denklem; p++) {
        		if (fabs(katsayimatris[p][i]) > fabs(maxVal)) {
            		maxVal = katsayimatris[p][i];
            		maxIndex = p;
        		}
    		}
    		if (maxIndex != i) {
    			tmp=sonuc[i];
    			sonuc[i]=sonuc[maxIndex];
    			sonuc[maxIndex]=tmp;
        		// matris satırlarını değiştirme
        		for (int p = 0; p < denklem; p++) {
            		double temp = katsayimatris[i][p];
            		katsayimatris[i][p] = katsayimatris[maxIndex][p];
            		katsayimatris[maxIndex][p] = temp;
        		}
    		}
			for(j=i+1;j<denklem;j++){
				katsayi = -katsayimatris[j][i]/katsayimatris[i][i];
				sonuc[j] += sonuc[i]*katsayi;
				for(k=0;k<denklem;k++){
					katsayimatris[j][k] += katsayimatris[i][k]*katsayi;
				}
			}
		
	}
	for(i=denklem-1;i>-1;i--){
		tmp=0;
		if(i==denklem-1){
			deger[i]=sonuc[i]/katsayimatris[i][i];
		}
		else{
			for(k=denklem-1;k>i;k--){
				tmp+= deger[k]*katsayimatris[i][k];
			}
			deger[i]= (sonuc[i]-tmp)/katsayimatris[i][i];
		}
	}
	for(i=0;i<denklem;i++){
		printf("\n%d. degisken = %lf",i+1,deger[i]);
	}
	
}





