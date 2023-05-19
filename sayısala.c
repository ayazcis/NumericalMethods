#include <stdio.h>
#include <math.h>
#define n 100
int fonksiyonderece();
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
void trapez();
void simpson();
void gaussSeidel();
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
		else if(choice==5){
			gausselemination();
		}
		else if(choice==8){
			simpson();
		}
		else if(choice==9){
			trapez();
		}
		gaussSeidel();
		
		
		
		
		
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
	double matris[n][n],det=0.0,birim[n][n],katsayi,temp,maxVal;
	int boyut,i=0,j,k,p,maxIndex;
	printf("\nMatrisin boyutunu giriniz");
	scanf("%d",&boyut);
	matrisal(matris,boyut);
	if(boyut==1){
		printf("\nMatrisin tersi: %lf",1/matris[0][0]);
	}
	else{
		for(i=0;i<boyut;i++){// birim matris olusturma
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
    		maxIndex = i;
    		maxVal = matris[i][i];
   			for (p = i + 1; p < boyut; p++) { // max elemanı bulma
        		if (fabs(matris[p][i]) > fabs(maxVal)) {
            		maxVal = matris[p][i];
            		maxIndex = p;
        		}
    		}
    		if (maxIndex != i) {
        		// matris satırlarını değiştirme
        		for (p = 0; p < boyut; p++) {
            		temp = matris[i][p];
            		matris[i][p] = matris[maxIndex][p];
            		matris[maxIndex][p] = temp;
            		temp = birim[i][p]; //birim matris için de aynısını yapma
            		birim[i][p] = birim[maxIndex][p];
            		birim[maxIndex][p] = temp;
        		}
    		}
			for(j=i+1;j<boyut;j++){ //üst üçgen yapma
				katsayi = -matris[j][i]/matris[i][i];
				for(k=0;k<boyut;k++){
					matris[j][k] += matris[i][k]*katsayi;
					birim[j][k] +=birim[i][k]*katsayi;
				}
			}
		
		}
		det = matris[boyut-1][boyut-1]*matris[boyut-2][boyut-2];
		for(i=boyut-3;i>-1;i--){                                       //det bulma
			det = matris[i][i]*pow(-1,(i+i))*det;
		}
		for(i=boyut-1;i>0;i--){
			for(j=i-1;j>-1;j--){ //alt üçgen yapma
				katsayi = -matris[j][i]/matris[i][i];
				for(k=0;k<boyut;k++){
					matris[j][k] += matris[i][k]*katsayi;
					birim[j][k] +=birim[i][k]*katsayi;
				}
			}
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
    		maxIndex = i;
    		maxVal = katsayimatris[i][i];
   			for (p = i + 1; p < denklem; p++) {  // max elemanı bulma 
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
        		for (p = 0; p < denklem; p++) {
            		temp = katsayimatris[i][p];
            		katsayimatris[i][p] = katsayimatris[maxIndex][p];
            		katsayimatris[maxIndex][p] = temp;
        		}
    		}
			for(j=i+1;j<denklem;j++){ //üst üçgen yapma
				katsayi = -katsayimatris[j][i]/katsayimatris[i][i];
				sonuc[j] += sonuc[i]*katsayi;
				for(k=0;k<denklem;k++){
					katsayimatris[j][k] += katsayimatris[i][k]*katsayi;
				}
			}
		
	}
	for(i=denklem-1;i>-1;i--){//üst üçgen matristen değerleri bulma
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
	for(i=0;i<denklem;i++){ //yazdırma
		printf("\n%d. degisken = %lf",i+1,deger[i]);
	}
	
}
void trapez(){
	int derece,a;
	double katsayi[n],kucuk,buyuk,h,S,i;
	derece=fonksiyonderece();
	fonkkatsayi(katsayi,derece);
	printf("\nN kac? ");
	scanf("%d",&a);
	printf("\nAraligi once kucuk sonra buyuk olmak uzere giriniz.");
	scanf("%lf %lf",&kucuk,&buyuk);
	h=(buyuk-kucuk)/a;
	S = (fonksonuc(kucuk,derece,katsayi)+fonksonuc(buyuk,derece,katsayi))/2;
	for(i=kucuk+h;i<buyuk;i+=h){
		S += fonksonuc(i,derece,katsayi);
	}
	S*=h;
	printf("\nSonuc: %lf\n",S);
}
void simpson(){
	int simp,derece,a,i;
	double katsayi[n],kucuk,buyuk,S=0.0,h,kucukholder,buyukholder,x1,x2;
	printf("\n1/3 icin 1'e , 3/8 icin 2'ye basiniz.");
	scanf("%d",&simp);
	if(simp==1){
		derece=fonksiyonderece();
		fonkkatsayi(katsayi,derece);
		do{
			printf("\nN kac? ");
			scanf("%d",&a);
		}while(a%2!=0);
		printf("\nAraligi once kucuk sonra buyuk olmak uzere giriniz.");
		scanf("%lf %lf",&kucuk,&buyuk);
		h=(buyuk-kucuk)/a;
		S= fonksonuc(kucuk,derece,katsayi)+fonksonuc(buyuk,derece,katsayi);
		for(i=1;i<a;i++){
			if(i%2==0){
				S+= 2*fonksonuc(kucuk+(i)*h,derece,katsayi);
			}
			else{
				
				S+= 4*fonksonuc(kucuk+(i)*h,derece,katsayi);
			}
		}
		S*=h/3;
		printf("\nSonuc: %lf\n",S);

	}
	else if(simp==2){
		derece=fonksiyonderece();
		fonkkatsayi(katsayi,derece);
		printf("\nN kac? ");
		scanf("%d",&a);
		printf("\nAraligi once kucuk sonra buyuk olmak uzere giriniz.");
		scanf("%lf %lf",&kucuk,&buyuk);
		h=(buyuk-kucuk)/a;
		S=0;
		buyukholder=buyuk;
		kucukholder=kucuk;
		for(i=0;i<a;i++){
			kucuk = kucukholder +i*h;
			buyuk = buyukholder - ((a-i-1)*h);
			x1= fonksonuc(kucuk+(buyuk-kucuk)/3,derece,katsayi);
			x2= fonksonuc(kucuk+(2*(buyuk-kucuk)/3),derece,katsayi);
			S+= ((buyuk-kucuk)/8)*(fonksonuc(kucuk,derece,katsayi)+ fonksonuc(buyuk,derece,katsayi)+3*x1+3*x2);
		}
		printf("\nSonuc: %lf\n",S);
		
	}
}
void gaussSeidel(){
	int denklem,i,j,maxIndex,p;
	double katsayimatris[n][n],sonuc[n],bas[n],hata,farklar[n],maxfark=100,maxVal,tmp,temp,prev;
	printf("\nKac tane denklem gireceksiniz? (Bilinmeyen sayisiyla esit olmali) ");
	scanf("%d",&denklem);
	printf("\nDenklemlerin katsayilar matrisini giriniz. ");
	gausskatsayial(katsayimatris,denklem,denklem);
	printf("\nDenklemlerin sonuclarini giriniz: ");
	for(i=0;i<denklem;i++){
		printf("\n%d. denklemin sonucu: ",i+1);
		scanf("%lf",&sonuc[i]);
	}
	printf("\nIstenilen min hatayi giriniz ");
	scanf("%lf",&hata);
	for(i=0;i<denklem;i++){
		printf("\n%d. bilinmeyenin baslangic degeri: ",i+1);
		scanf("%lf",&bas[i]);
	}
	for(i=0;i<denklem-1;i++){
		maxIndex = i;
    	maxVal = katsayimatris[i][i];
   		for (p = i + 1; p < denklem; p++) {  // max elemanı bulma 
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
       		for (p = 0; p < denklem; p++) {
            	temp = katsayimatris[i][p];
            	katsayimatris[i][p] = katsayimatris[maxIndex][p];
           		katsayimatris[maxIndex][p] = temp;
       		}
    	}
	}
	while(maxfark>hata){
		for(i=0;i<denklem;i++){//her satırdaki kösegen elemanının değeri bulunuyor
			prev=bas[i];
			tmp=sonuc[i];
			for(j=0;j<denklem;j++){
				if(i!=j){
					tmp-=katsayimatris[i][j]*bas[j];
				}
			}
			bas[i]=tmp/katsayimatris[i][i];
			farklar[i]=fabs(bas[i]-prev); //önceki değerleriyle farklarını kaydet
			
		}
		maxfark = farklar[0];
		for(i=1;i<denklem;i++){//en büyük farkı bul
			if(farklar[i]>maxfark){
				maxfark= farklar[i];
			}
		}
		
	}
	for(i=0;i<denklem;i++){
		printf("\n%d. degisken = %lf",i+1,bas[i]);
	}
	
	
}




