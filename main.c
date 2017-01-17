#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void racun_za_izlaz(int blagajnik, int izlaz)
{
    printf("             -ROUTE 66-\n\n");

    srand(time(NULL));
    int r=rand(); //Daje neki nasumican broj

    time_t trenutno_vrijeme;
    char* vrijeme;

    trenutno_vrijeme = time(NULL);
    vrijeme = ctime(&trenutno_vrijeme); //tekstualno reprezentuje vrijeme (trenunto vrijeme)

    FILE *datoteka, *datoteka1;
    char rijec[100];
    int kategorija, ulaz,broj;
    double osnovica, cijenaa, pdv, uplaceno;

    if((datoteka1=fopen("potvrda.txt","r")))
    {
        while(fscanf(datoteka1,"%s : %d",rijec, &broj)!=EOF)
        {
            if(!strcmp(rijec,"Uredjaj"))
                ulaz=broj;
        }

        fclose(datoteka1);
    }

    printf("Blagajnik : %d", blagajnik);

    printf("\nDatum     : %s", vrijeme);

    printf("Stanica   : %d", izlaz);

    printf("\n---------------------------------------------\n");
    printf("             RACUN br. %d\n",r);

    printf("Unesite kategoriju vozila (Motor-1,Automobil-2,Autobus-3,Kamion-4): ");
    scanf("%d", &kategorija);
    osnovica=cijena(ulaz,izlaz,kategorija);
    pdv=(osnovica*17)/100;
    cijenaa=osnovica+pdv;

    printf("\nCijena za 1.kategoriju : %.2lf", cijenaa);
    printf("\nOsnovica               : %.2lf", osnovica);
    printf("\nPDV 17%%                : %.2lf", pdv);
    printf("\n\nUplaceno               : ");
    scanf("%lf", &uplaceno);
    printf("Kusur                  : %.2lf", uplaceno-cijenaa);

    printf("\n---------------------------------------------\n");
    printf("\n           HVALA, SRECAN PUT!");

    if((datoteka=fopen("racun_za_izlaz.txt","w")))
    {
        fprintf(datoteka,"             -ROUTE 66-\n\n");
        fprintf(datoteka,"Blagajnik : %d", blagajnik);

        fprintf(datoteka,"\nDatum     : %s", vrijeme);

        fprintf(datoteka,"Stanica   : %d", izlaz);

        fprintf(datoteka,"\n---------------------------------------------\n");
        fprintf(datoteka,"             RACUN br. %d\n",r);
        fprintf(datoteka,"\nCijena za 1.kategoriju : %.2lf", cijenaa);
        fprintf(datoteka,"\nOsnovica               : %.2lf", osnovica);
        fprintf(datoteka,"\nPDV 17%%                : %.2lf", pdv);
        fprintf(datoteka,"\n\nUplaceno               : %.2lf", uplaceno);
        fprintf(datoteka,"\nKusur                  : %.2lf", uplaceno-cijenaa);

        fprintf(datoteka,"\n---------------------------------------------\n");
        fprintf(datoteka,"\n           HVALA, SRECAN PUT!");
        fclose(datoteka);

    }

}
