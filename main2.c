#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void korisnicki_meni_izlaz()
{
    int broj;
    int blagajnik, izlaz; //argumenti koje prima funkcija za izdavanje racuna pri izlasku sa autoputa

    do
    {
       printf("\n----------------------------------------------------------------------------------------------------------\n");
       printf("Izaberite opciju:\n1 - Izdavanje racuna na izlazu sa autoputa\n2 - Pomoc\n3 - Odjava sa sistema\n0 - Kraj\n\n");
       printf("----------------------------------------------------------------------------------------------------------\n");
       scanf("%d", &broj);

       if(broj==1) //ako je korisnik izabrao opciju za izdavanje racuna na izlazu sa autoputa
       {
           racun_za_izlaz(blagajnik, izlaz);
           printf("Zahtjev je uspjesno obavljen!\n");
       }

    else if(broj==2) //ako je korisnik izabrao opciju za pomoc pri radu
    {
        printf("\nNakon sto je prijava na sistem prosla uspjesno, korisniku se prikazuje meni sa opcijama za rad na izlazu sa autoputa, koji ukljucuje: izdavanje racuna, pomoc pri koristenju sistema i odjavu sa sistema.\nSvaka od prethodno navedenih opcija numerisana je brojevima 1, 2, 3 i 0, respektivno. U skladu sa potrebom, korisnik unosi jedan od ponudjenih brojeva, koji simbolizuje zeljenu radnju. Mogucnost odabira traje dok se ne unese 0 za kraj.\nPri izlazu sa autoputa, korisnik je duzan izdati racun, te u skladu s tim treba izabrati opciju 1.\n");
    }

    else if(broj==3) //ako je korisnik izabrao opciju za odjavu sa sistema
    {
        system("cls");
    }

    else if(broj!=0)
        printf("Greska pri odabiru opcije, pokusajte ponovo!\n");
    }
    while(broj!=0);

    printf("Kraj!\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
}

