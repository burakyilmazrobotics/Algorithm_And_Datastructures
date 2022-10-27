#include <stdio.h>
#include <math.h>

struct guc_kaynagi {
    float gerilim;
    float ic_direnc;
};

float guc_hesapla(float Ri, float Rl, float Vi)
{
    float sonuc, guc;
    guc=((Rl*Rl)*Vi)/(Rl+Ri);
    sonuc= guc;
    return sonuc;
}

float kayip_guc_hesapla (float Ri, float Rl, float Vi)
{
    float sonuc, guc;
    guc=((Ri*Ri)*Vi)/(Rl+Ri);
    sonuc= guc;
    return sonuc;

}

int main()
{
    float Vi, Ri, Pl, Pi, Rl_sayac, fark, ntolerans, ptolerans;
    struct guc_kaynagi deney1;
    printf ("\n Guc kaynagi gerilimini giriniz ");
    scanf ("%f", &Vi);
    printf ("\n Guc kaynagi direncini giriniz ");
    scanf ("%f", &Ri);
    printf ("\n Negatif tolerans degerini giriniz");
    scanf ("%f", &ntolerans);
    printf ("\n pozitif tolerans degerini giriniz ");
    scanf ("%f", &ptolerans);
    deney1.gerilim=Vi;
    deney1.ic_direnc=Ri;
    Rl_sayac=0;
    
    printf("| Ic Direnc | Yuk Direnci RL | Harcanan Guc | Kayip Guc | ___Fark___ | \n");
    
    while (Rl_sayac < 500) {
        Pl=guc_hesapla(deney1.ic_direnc,Rl_sayac,deney1.gerilim);
        Pi=kayip_guc_hesapla(deney1.ic_direnc,Rl_sayac,deney1.gerilim);
        fark=Pl-Pi;
       
	   
	   if (fark ==0 ){
       	
       	printf("|    %.2f |       %.2f   |     %.2f   |    %.2f |    %.2f  | <-- Ideal Yuk Direnci \n", Ri, Rl_sayac, Pl,  Pi, fark);
       }
       else if (fark >=ntolerans && fark <= ptolerans ){
       	
       	printf("|    %.2f |       %.2f   |     %.2f   |    %.2f |    %.2f  | <-- Uygun yuk direnci araligi \n", Ri, Rl_sayac, Pl,  Pi, fark);
       	
       	
	   }
	    else{
		

        printf("|    %.2f |       %.2f   |     %.2f   |    %.2f |    %.2f  | \n", Ri, Rl_sayac, Pl,  Pi, fark);
        }
        Rl_sayac = Rl_sayac + 5;
    }
}