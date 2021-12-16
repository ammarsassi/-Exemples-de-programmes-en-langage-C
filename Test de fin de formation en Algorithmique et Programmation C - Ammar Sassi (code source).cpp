 /*--------------------------------------------------------------------------------------------------------------*/
 /* Ce fichier est en réponse au test de fin de la deuxiéme semaine de formation JEE Developer assurée par #CORP,
  * module traîté "Algorithmique et Développemnt C".
  * 
  * Programme1 : Recursivité
  * Programme2 : Opposés ou Inverses
  * Programme3 : Distance entre villes
  *
  * @ Ammar Sassi
  * E-mail: sasssi.ammar@hotmail.com
  * LinkedIn : https://www.linkedin.com/in/ammar-sassi
  * GitHub : https://github.com/ammarsassi/ammarsassi
  *
  * réalisé le 21/08/2021
  /*---------------------------------------------------------------------------------------------------------------*/
 
 // Déclaration des biliothéques à utiliser
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 #include <math.h>
 #include <windows.h>

 



 // Code source du programme1 : <Recursivité>
 //------------------------------------------
 // Ce code permet de déterminer combien d'occurences d'une lettre donnée se trouve dans une chaîne de caratères
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 int Occurences(char *ch, char c, int i, int occur)
 {

  while(ch[i]!='\0')
    {
    	if(ch[i]==c)
    	{
    		++i;    
    	    Occurences(ch, c, i, occur);
    	    ++occur;
    	}
    	else
    	++i;
    }
    
	return occur;
 }
 
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 // Code source du programme2 : <Tableaux>
 //----------------------------------------
 
 // Code source du sous_programme2.1 : <SontInvOuOpp>
 //---------------------------------------------------
 // Ce code permet de verifier si deux entier sont opposés (leurs somme =0) ou inverses (leurs produit =1) 
 // tout en sachant que la valeur 0 n'admet ni u opposé ni un inverse
 // le programme retourne 1 pour Vrai, 0 pour Faux
 //--------------------------------------------------------------------------------------------------------
 int SontInvOuOpp(int a, int b)
 {
 	if((a!=0) && (b!=0) && ((a+b)==0) || ((a*b)==1))
 	return 1;
 	else 
	return 0 ;
 }
  
 // Une autre version pour les réels
 float SontInvOuOppF(float a, float b)
 {
 	if((a!=0) && (b!=0) && ((a+b)==0) || ((a*b)==1))
 	return 1;
 	else 
	return 0 ;
 }
 
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 // Code source du sous_programme2.2 : <ExisteInvOuOppConsecutifs>
 //----------------------------------------------------------------
 // Ce permet de cherche combien de paire d'entiers consecutifs opposés ou inverses se trouvent dans un tableau donné
 //-------------------------------------------------------------------------------------------------------------------
 int ExisteInvOuOppConsecutifs(int T[], int n)
 {
	int paires =0;
	int i=0;
	
	while(i<n)
	{
		if(SontInvOuOpp(T[i], T[i+1])==1)
		paires++;
		
		i++;
	}

 		return paires;
  }
  
 // Une autre version pour les réels
 int ExisteInvOuOppConsecutifsF(float T[], int n)
 {
	int paires =0;
	int i=0;
	
	while(i<n)
	{
		if(SontInvOuOppF(T[i], T[i+1])==1)
		paires++;
		
		i++;
	}

 		return paires;
  } 
  
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 // Code source du sous_programme2.3 : <ExisteInvouOpp>
 //-----------------------------------------------------
 // Ce permet de cherche combien de paire d'entiers opposés ou inverses se trouvent dans un tableau donné 
 //------------------------------------------------------------------------------------------------------
 int ExisteInvOuOpp(int T[], int n)
 {
	int paires =0;
	int i=0;
	
	while(i<n-2)
	{
		int j=i+2;
		
		while(j<n)
		{
			if(SontInvOuOpp(T[i], T[j])==1)
			paires++;
			j++;
		}
		
		i++;
	}
 	return paires;
  }
  
 // Une autre version pour les réels
 int ExisteInvOuOppF(float T[], int n)
 {
	int paires =0;
	int i=0;
	
	while(i<n-2)
	{
		int j=i+2;
		
		while(j<n)
		{
			if(SontInvOuOppF(T[i], T[j])==1)
			paires++;
			j++;
		}
		
		i++;
	}
 	return paires;
  }  
  
 //------------------------------------------------------------------------------------------------------------------------------------------------------------ 
 
 
 // Code source du'une procédure pour le remplissage d'un tableau d'éntiers
 //------------------------------------------------------------------------
  void RemplirTableau(int T[], int n)
 {
	int x;
	for(int i=0; i<n; i++)
	{
		printf("\nEntrer la valeur de l'entier n %d -->\t", i);
		scanf("%d", &x);
        fflush(stdin); 
        T[i]=x;		
	}
 }
 
 // Une autre version pour les réels
  void RemplirTableauF(float T[], int n)
 {
	float x;
	for(int i=0; i<n; i++)
	{
		printf("\nEntrer la valeur du reel n %d -->\t", i);
		scanf("%f", &x);
        fflush(stdin); 
        T[i]=x;		
	}
 }
 
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 // Code source du programme3 : Villes
 //------------------------------------
 // Définition des structures de données Ville et Carte (qui est un ensemble de villes)
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 const int Nmax=1000;
 
 typedef struct 
 {
 	char *nom=(char *) malloc(sizeof(nom));
 	float x;
 	float y;
 	int nbHabitants;
 }Ville;
 
 typedef struct
 {
 	int NVilles;
	Ville TVilles[Nmax]; 
 }Carte;
 
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
  
 // Code source de la fonction1 : <VilleExistante>
 //--------------------------------------------
  int VilleExistante(Carte *C, char *nomVille)
  {
  	int n = C->NVilles;
  	int i=0;
  	while((i<n) && (C->TVilles[i].nom!=NULL) && (strcmp(C->TVilles[i].nom, nomVille)!=0))
  	i++;
  	
  	if((i==n) || (C->TVilles[i].nom==NULL))
  	return 0;
  	else
  	return 1;
  	
  }
  
  
 // Code source de la fonction2 : <AfficherVille>
 //-----------------------------------------------

  void AfficherVilles(Carte *C)
  {
  	for(int i=0; i<C->NVilles; i++)
  	  printf("\n\tNom de la ville n %d : %s  -   Nombre d'habitants :  %d      \n\n\t\t\t\tAlt:   %f   -   Long :    %f\n", i+1, C->TVilles[i].nom, C->TVilles[i].nbHabitants, C->TVilles[i].x,C->TVilles[i].y);
	  printf("\nTaper une touche pour continuer\n");
  }
  
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 // Code source du sous_programme3.1 : <VilleLaPlusPeuplée>
 //--------------------------------------------------------
 // Ce code permet de trier les éléments (villes) du tableau Carte selon un ordre décroissant (par nombre d'habitant) et affiche 
 // le premier élément du tableau qui correspondra à la ville la plus peuplée
 // ----------------------------------------------------------------------------------------------------------------------------
 
 void TriDecroissant (Carte *C)
 {
 	Ville Sauv;
 	int i,j;
 	
    for(j=1;j<=C->NVilles;j++)
    {
        for(i=0;i<C->NVilles-1;i++)
        {
            if ( C->TVilles[i].nbHabitants < C->TVilles[i+1].nbHabitants ) 
			{
               Sauv = C->TVilles[i];
               C->TVilles[i] = C->TVilles[i+1];
               C->TVilles[i+1] = Sauv;
           }
        } 
    }

 }
 
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 // Code source du sous_programme3.2 <Les5VillesLesMoinsPeuplees>
 //-----------------------------------------------------------  ---
  
 // Ce code permet de trier les éléments (villes) du tableau Carte selon un ordre croissant (par nombre d'habitant) et affiche 
 // les cinq premier élément du tableau qui correspondra aux cinq villes les moins peuplées
 // --------------------------------------------------------------------------------------------------------------------------
 
 void TriCroissant (Carte *C)
 {
 	Ville Sauv;
 	int i,j;
 	
    for(j=1;j<=C->NVilles;j++)
    {
        for(i=0;i<C->NVilles-1;i++)
        {
            if ( C->TVilles[i].nbHabitants > C->TVilles[i+1].nbHabitants ) 
			{
               Sauv = C->TVilles[i];
               C->TVilles[i] = C->TVilles[i+1];
               C->TVilles[i+1] = Sauv;
           }
        } 
    }

 }
   
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  

 
 // Code source du sous_programme3.4 <RechercheCoordonnées>
 //--------------------------------------------------------
 // Ce code retourne les coordonnees d'une ville rechercher dans la carte
 //----------------------------------------------------------------------  
  int RechercheCoordonnees(Carte *C, char *nomVille, float T[])
  {
	int i =0; 
  	int trouvee =0;

  	
  	while((i<C->NVilles) && (trouvee!=1))
  	{
  		if(strcmp(C->TVilles[i].nom,nomVille)==0)
  		trouvee =1;
  		else
  		{
		  trouvee =0;
  		  i++;
  	    }
  	}
  	
  	if(trouvee==1)
  	{
  		T[0]=C->TVilles[i].x;
  		T[1]=C->TVilles[i].y;
	
  		return 1;
	
    }
    else
      	return 0;
  	
  	
  }
  
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 // Fonctions systéme
 //------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 void color(int t,int f)
 { 
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
 }
 
 
 
 
 
 // Fonction main
 //------------------------------------------------------------------------------------------------------------------------------------------------------------

 int main()
 {
   
    // Modification de la couleur de la couleur de fond et de texte de la console 
           
    color (12,0);
    system("cls");
    goto menu_p;
   
    // Affichage du menu
menu_p :
	system("cls");
	printf("________________________________________________________________________\n");	
    printf("Bienvenue\n Ce present travail est en reponse au test de fin de la 2eme semaine de la\n formation JEE Developer assuree par #CORP, il contient les programmes suivant:\n");
    printf("\t Programme 1 : <Occurences> --> un programme qui permet de trouver le\n\t\t\tnombre d'occurences d'un caractere dans une phrase\n\t\t\tRemarque : ce programme traite la recursivite\n\n");
    printf("\t Programme 2 : <Opposes/Inverses> --> un programme qui permet d executer\n\t\t\tun nombre de traitements sur des entiers pour determiner\t\t\tles opposes et les inverses entre eux\n\t\t\tRemarque : ce programme manipule les tableaux\n\n");
 	printf("\t Programme 3 : <Villes> --> un programme qui permet de calculer la\n\t\t\tdistance entre deux villes dans une cite\n\t\t\tRemarque : ce programme traite les structures de donnees\n");
	printf("@auteur: Ammar Sassi\nE-mail: sassi.ammar@hotmail.com\nLinkedIn: https://www.linkedin.com/in/ammar-sassi\n");
	printf("________________________________________________________________________\n");

	
	// Choix du programme à exécuter
	int choix;
	
	do
	{			
       	printf("Taper votre choix 1, 2 ou 3 pour executer le programme voulu, 0 pour quitter :\n\n-->\t");
        scanf("%d", &choix);
        fflush(stdin); 	
    }while((choix<0) || (choix>3));


    // Execution du programme choisi
    switch(choix)
    {
    	case 1 :
    		{
				// Programme1 <Occurences>
				system("cls");   
				printf("\n__________________________\n");								
				printf("Programme 1 : Occurrences\n");
				printf("__________________________\n");
				
				char *phrase=(char *) malloc(sizeof(phrase));
	            char c;		
						
				char reponse1;
				
			    do
				{
				 printf("\nTaper y pour continuer, p pour retourner au menu principale ou q pour quitter\n-->\t");
                 scanf("%c", &reponse1);
			     fflush(stdin);
		     	}while((reponse1!='y') && (reponse1!='p') && (reponse1!='q'));

			    if(reponse1=='y')
			    {
				    system("cls");
					printf("__________________________\n");					    
					printf("Programme 1 : Occurrences\n");
					printf("__________________________\n");	
									    	
			  	
				 	printf("\nEntrer une phrase : -->\t");
				 	scanf("%[^\n]s",phrase);
				 	fflush(stdin);
				 	
				 	printf("\nEntrer une lettre a chercher : -->\t");
				 	scanf("%c",&c);
				 	fflush(stdin);	 	
					             

					int occur =  Occurences(phrase, c, 0, 0);
					
				 	printf("\n-->\tLe nombre d'occurence du caractere %c dans la phrase donnee est %d\n", c, occur);

					char reponse2;

					do 
					{
						printf("\nTaper p pour retourner au menu principale ou q pour quitter\n-->\t");
						scanf("%c", &reponse2);
						fflush(stdin);	
                    }while((reponse2!='p') && (reponse2!='q'));
							
					if(reponse2 == 'p')
					goto menu_p;	
					else if(reponse2 == 'q')
						exit(0);		

	            }
	            
	            else if(reponse1 == 'p')
					goto menu_p;
				    else if(reponse1 == 'q')
						    exit(0);				    


			 } break;
			 
menu2 :			 
		case 2 :
			{
			 	// Programme2 <OpposesInverses>
				system("cls"); 
				printf("\n______________________________\n");			  			 	
			 	printf("\Programme 2 : Inverse/Oposses\n");
				printf("______________________________\n\n");			 	
				printf("\t Sous_programme 1 : <SontInvOuOpp> --> Est-ce que deux entiers sont\n\t\t\t\t Inv/Opp\n");
			    printf("\t Sous_programme 2 : <ExisteInvOuOppConsecutifs> --> Exist-t-il paires\n\t\t\t\t d'entiers consecutifs Inv/Opp?\n");
			 	printf("\t Sous_programme 3 : <ExisteInvOuOpp> --> Combien y a-t-il de paires\n\t\t\t\t d'entiers Inv/Opp non consecutifs?'\n");
			 	printf("\t Sous_programme 4 : <NbrInvOuOpp> --> Compter tous les paires que ce\n\t\t\t\t soit consecutifs ou non\n");
				printf("________________________________________________________________________\n");
				
				int choix_s;
					
				do
				{			
      				printf("\nTaper votre choix 1, 2, 3 ou 4 pour executer un sous programme 5 pour \nretourner au menu principale ou 0 pour quitter :\n\n-->\t");
                    scanf("%d", &choix_s);
                    fflush(stdin); 	
                }while(choix_s<0 || choix_s>5);
            
                
                switch(choix_s)
                {
                	case 1 :
                		{
                			// Sous_programme2.1 <SontInvOuOpp>
				            system("cls");
	                		printf("\nProgramme SontInvOuOpp\n");
							printf("______________________\n\n");	
							
							char reponse1;	
							
							do
							{		    
                			printf("\nTaper E pour executer programme_Entiers, R pour executer programme_Reels:\n\n-->\t");
				            scanf("%c", &reponse1);
			                fflush(stdin);       
						    }while((reponse1!='E')&&(reponse1!='R'));
   			
                			if(reponse1=='E')
                			{
                				system("cls");
	                			printf("\nProgramme SontInvOuOpp (Entiers)\n");
								printf("_________________________________\n\n");
								
								int x1,y1;			 
								               
								printf("Entrer deux entiers :\n");
				                printf("\n-->\t1er entier :\t");
				                scanf("%d",&x1);
							    fflush(stdin);
							    
				                printf("\n-->\t2eme entier :\t");
				                scanf("%d",&y1);
							    fflush(stdin);
							    
				                printf("\n-->\tSont inverses ou oposses!!! Tapez une touche pour connaitre ...\n");			    
				                getch();
				                
								if((SontInvOuOpp(x1,y1))==1)
						    	printf("\n-->\tVrai\n\tLes deux entiers que vous avez donner %d, %d \n\tsont soit inverses soit oposses\n", x1,y1);
						        else
						    	printf("\n-->\tFaux\n\tLes deux entiers que vous avez donner %d, %d \n\tne sont ni inverses ni oposses\n", x1,y1);	
							}	
									           
				            else
				            {
				            	system("cls");
	                			printf("\nProgramme SontInvOuOpp (Reels)\n");
								printf("_______________________________\n\n");
								
								float x2,y2;			 
								               
								printf("Entrer deux reels :\n");
				                printf("\n-->\t1er reel :\t");
				                scanf("%f", &x2);
							    fflush(stdin);
							    
				                printf("\n-->\t2eme reel :\t");
				                scanf("%f", &y2);
							    fflush(stdin);
							    
				                printf("\n-->\tSont inverses ou oposses!!! Tapez une touche pour connaitre ...\n");			    
				                getch();	
								if((SontInvOuOppF(x2,y2))==1)
						    	printf("\n-->\tVrai\n\tLes deux reels que vous avez donner %f, %f \n\tsont soit inverses soit oposses\n", x2,y2);
						        else
						    	printf("\n-->\tFaux\n\tLes deux reels que vous avez donner %f, %f \n\tne sont ni inverses ni oposses\n", x2,y2);												            	
							}


							char reponse2;	
							
							do
							{		    
			    				printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
	    			            scanf("%c", &reponse2);
			                    fflush(stdin);       
						    }while((reponse2!='m')&&(reponse2!='p')&&(reponse2!='q'));

						    if(reponse2=='m')
						       goto menu2;
						       else if(reponse2 == 'p')
						         goto menu_p;
						         else if(reponse2=='q')
						         exit(0);
						    
						}break;
						
					
					case 2 :
						{
							// Programme2.2 <ExisteInvOuOppConsecutifs>
				            system("cls");
	                		printf("\nProgramme ExisteInvOuOppConsecutifs\n");
							printf("____________________________________\n\n");
								
							int nbr;
							printf("\nDonner la taille de tableau a traiter-->\t");
							scanf("%d", &nbr);
						    fflush(stdin);

							char reponse1;	
							
							do
							{		    
                    			printf("\nTaper E pour executer programme_Entiers, R pour executer programme_Reels:\n\n-->\t");
			    	            scanf("%c", &reponse1);
			                    fflush(stdin);       
						    }while((reponse1!='E')&&(reponse1!='R'));
							
                			if(reponse1=='E')
                			{	
								system("cls");													
	                			printf("\nProgramme ExisteInvOuOppConsecutifs pour entiers\n");
								printf("_________________________________________________\n\n");
								
								int Tab[nbr];												
								RemplirTableau(Tab, nbr);
								
				                printf("\n\n-->\tExiste-t-il une paire d entiers consecutifs qui sont\n\tInverses ou Oposses!!! Tapez une touche pour connaitre ...\n");								
				                getch();
															
								if(ExisteInvOuOppConsecutifs(Tab, nbr)!=0)
				                	printf("\n-->\tOui, il existe dans le tableau donne %d paire(s) d entiers\n\tconsecutifs qui soit Inverses ou Oposses.\n",ExisteInvOuOppConsecutifs(Tab, nbr));							
								else
				                	printf("\n-->\tNon, il n existe dans le tableau donne aucune paire d entiers\n\tconsecutifs qui soit Inverses ou Oposses.\n");							
				            }
				                
				            else
				            {
				            	system("cls");
	                			printf("\nProgramme ExisteInvOuOppConsecutifs pour entiers\n");
								printf("_________________________________________________\n\n");		
								
								float Tab[nbr];												
								RemplirTableauF(Tab, nbr);
								
				                printf("\n\n-->\tExiste-t-il une paire de reels consecutifs qui sont\n\tInverses ou Oposses!!! Tapez une touche pour connaitre ...\n");								
				                getch();
															
								if(ExisteInvOuOppConsecutifsF(Tab, nbr)!=0)
				                	printf("\n-->\tOui, il existe dans le tableau donne %d paire(s) de reels\n\tconsecutifs qui soit Inverses ou Oposses.\n",ExisteInvOuOppConsecutifsF(Tab, nbr));							
								else
				                	printf("\n-->\tNon, il n existe dans le tableau donne aucune paire de reels\n\tconsecutifs qui soit Inverses ou Oposses.\n");											                	
							}
				                
						
							char reponse2;	
							
							do
							{		    
				    			printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
			    	            scanf("%c", &reponse2);
			                    fflush(stdin);       
						    }while((reponse2!='m')&&(reponse2!='p')&&(reponse2!='q'));

						    if(reponse2=='m')
						       goto menu2;
						       else if(reponse2 == 'p')
						         goto menu_p;
						         else if(reponse2=='q')
						         exit(0);							
							
						}break;
						
					case 3 :
						{
							// Programme2.3 <ExisteInvouOpp>
							system("cls");							
                			printf("\nProgramme ExisteInvOuOpp\n");
							printf("______________________\n\n");
							
							int nbr;
							printf("\nDonner la taille de tableau a traiter-->\t");
							scanf("%d", &nbr);
						    fflush(stdin);

						        
							char reponse1;	
							
							do
							{		    
                    			printf("\nTaper E pour executer programme_Entiers, R pour executer programme_Reels:\n\n-->\t");
			    	            scanf("%c", &reponse1);
			                    fflush(stdin);       
						    }while((reponse1!='E')&&(reponse1!='R'));
							
                			if(reponse1=='E')
                			{	
								system("cls");                			
	                			printf("\nProgramme ExisteInvOuOpp pour entiers\n");
								printf("______________________________________\n\n");	
								                			
								int Tab[nbr];												
								RemplirTableau(Tab, nbr);
								
				                printf("\n\n-->\tCombien de paires d entiers inverses ou oposses se trouvent\n\tdans ce tableau!!! Tapez une touche pour connaitre ...\n");								
				                getch();							
								
								if(ExisteInvOuOpp(Tab, nbr)!=0)
				                	printf("\n-->\tIl existe dans le tableau donne %d paire(s) d entiers\n\t\qui soit Inverses ou Oposses.\n"),ExisteInvOuOpp(Tab, nbr);							
								else
				                	printf("\n-->\tIl n existe dans le tableau donne aucune paire d entiers\n\tqui soit Inverses ou Oposses.\n");		
							}
							
							else
							{
								system("cls");
	                			printf("\nProgramme ExisteInvOuOpp pour reels\n");
								printf("_____________________________________\n\n");	
																
								float Tab[nbr];												
								RemplirTableauF(Tab, nbr);
								
				                printf("\n\n-->\tCombien de paires de reels inverses ou oposses se trouvent\n\tdans ce tableau!!! Tapez une touche pour connaitre ...\n");								
				                getch();							
								
								if(ExisteInvOuOppF(Tab, nbr)!=0)
				                	printf("\n-->\tIl existe dans le tableau donne %d paire(s) d entiers\n\t\qui soit Inverses ou Oposses.\n"),ExisteInvOuOppF(Tab, nbr);							
								else
				                	printf("\n-->\tIl n existe dans le tableau donne aucune paire d entiers\n\tqui soit Inverses ou Oposses.\n");										
							}

							char reponse2;	
							
							do
							{		    
		    					printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		            scanf("%c", &reponse2);
		    	                fflush(stdin);       
						    }while((reponse2!='m')&&(reponse2!='p')&&(reponse2!='q'));

						    if(reponse2=='m')
						       goto menu2;
						       else if(reponse2 == 'p')
						         goto menu_p;
						         else if(reponse2=='q')
						         exit(0);
								 										
						}break;
					
					case 4 :
						{
							// Programme2.4 <NbInvOuOpp>
							system("cls");   							
                			printf("\nProgramme NbInvOuOpp\n");
							printf("______________________\n\n");
							
							int nbr;
							
							printf("\nDonner la taille de tableau d entiers a remplir -->\t");
							scanf("%d", &nbr);
					        fflush(stdin);		

							char reponse1;	
							
							do
							{		    
                    			printf("\nTaper E pour executer programme_Entiers, R pour executer programme_Reels:\n\n-->\t");
			    	            scanf("%c", &reponse1);
			                    fflush(stdin);       
						    }while((reponse1!='E')&&(reponse1!='R'));
							
                			if(reponse1=='E')
                			{	
                				system("cls");  
                		    	printf("\nProgramme NbInvOuOpp pour entiers\n");
						     	printf("__________________________________\n\n");								 
								int Tab[nbr];												
								RemplirTableau(Tab, nbr);
								
				                printf("\n\n-->\tCombien existe-t-il de paires d entiers qui sont Inverses ou Oposses\n\tdans ce tableau!!! Tapez une touche pour connaitre ...\n");								
				                getch();							
								
								if((ExisteInvOuOppConsecutifs(Tab, nbr) + ExisteInvOuOpp(Tab,nbr))==0)
				                	printf("\n-->\tIl n existe dans le tableau donne aucune paire d entiers\n\t\qui soit Inverses ou Oposses.\n");							
								else
				                	printf("\n-->\tIl existe dans le tableau donne %d paires d entiers\n\tqui soit Inverses ou Oposses.\n", (ExisteInvOuOppConsecutifs(Tab, nbr) + ExisteInvOuOpp(Tab,nbr)));
				            }
				            
				            else
				            {
				            	system("cls");
                     			printf("\nProgramme NbInvOuOpp pour reels\n");
				    			printf("________________________________\n\n");				            	
								float Tab[nbr];												
								RemplirTableauF(Tab, nbr);
								
				                printf("\n\n-->\tCombien existe-t-il de paires d entiers qui sont Inverses ou Oposses\n\tdans ce tableau!!! Tapez une touche pour connaitre ...\n");								
				                getch();							
								
								if((ExisteInvOuOppConsecutifsF(Tab, nbr) + ExisteInvOuOppF(Tab,nbr))==0)
				                	printf("\n-->\tIl n existe dans le tableau donne aucune paire d entiers\n\t\qui soit Inverses ou Oposses.\n");							
								else
				                	printf("\n-->\tIl existe dans le tableau donne %d paires d entiers\n\tqui soit Inverses ou Oposses.\n", (ExisteInvOuOppConsecutifsF(Tab, nbr) + ExisteInvOuOppF(Tab,nbr)));
				            }				            	
			
							char reponse2;	
							
							do
							{		    
	     						printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		            scanf("%c", &reponse2);
	    		                fflush(stdin);       
						    }while((reponse2!='m')&&(reponse2!='p')&&(reponse2!='q'));

						    if(reponse2=='m')
						       goto menu2;
						       else if(reponse2 == 'p')
						         goto menu_p;
						         else if(reponse2=='q')
						         exit(0);																							

						}break;
						
				    case 5 : 
					    goto menu_p;
					case 0 :
						exit(0);
				}
			    
			} break;

			
		case 3 :
			{
			 	// Programme3 <Villes>
				system("cls");   	
				printf("\n_____________________\n\n");						 	
			 	printf("\Programme 3 : Villes\n");
				printf("_____________________\n\n");	
				
				printf("Initialisation de la carte geographique\n");
				printf("___________________________________________\n\n");
				
				int nbrVilles;
				
				do
				{  
				    printf("Donner nombre de villes dans cette carte -->\t");
				    scanf("%d", &nbrVilles);
					fflush(stdin);	
				}while(nbrVilles>1000);
				
			
				Carte *C=(Carte*)malloc(sizeof(Carte));

				float x,y;
				int nbrH;
				
							
				C->NVilles=nbrVilles;
				
				for(int i=0; i<nbrVilles; i++)
				{
					   char *nom=(char *)malloc(sizeof(nom));

					   printf("\n\t Donner nom de la ville numero %d sur la carte\n\t\t -->\t", i+1);
					   scanf("%s",nom);
			           fflush(stdin);

			           

			    	   C->TVilles[i].nom=nom;
			    	   fflush(stdin);
					   			    	
				       printf("\n\t Donner coordonnees x ou Latitude de la ville numero %d sur la carte\n\t\t -->\t", i+1);
					   scanf("%f",&x);
			    	   fflush(stdin);	
					   		    	
					   C->TVilles[i].x=x;	
			    	   
				       printf("\n\t Donner coordonnees y ou Longitude de la ville numero %d sur la carte\n\t\t -->\t", i+1);
					   scanf("%f",&y);
			    	   fflush(stdin);
					   	
					   C->TVilles[i].y=y;
					   		    	   
				       printf("\n\t Donner nombre d habitants de la ville numero %d sur la carte\n\t\t -->\t", i+1);
					   scanf("%d",&nbrH);
			    	   fflush(stdin);		

					   C->TVilles[i].nbHabitants=nbrH;

				}
				
				printf("\nInitialisation de la carte geographique terminee \n");
				printf("_________________________________________________\n\n");	
				AfficherVilles(C);	
				printf("___________________________________________________________________________\n\n");					
				
                getch();	
							
menu1 :		
                system("cls");			
				printf("\n_____________________\n\n");						 	
			 	printf("\Programme 3 : Villes\n");
				printf("_____________________\n");						 	
				printf("\n\t Sous_programme 1 : <VilleLaPlusPeuplee> --> ville la plus peuplee\n");
			    printf("\t Sous_programme 2 : <Les5VillesLesMoinsPeuplees> --> retourne une\n\t\t\t\tune selection des 5 villes les moins peuplees\n");
			 	printf("\t Sous_programme 3 : <DistanceVilles> --> retourne valeur de la distance\n\t\t\t\tentre deux villes donnees\n");
			 	printf("\t Sous_programme 4 : <RechercheCoordonnees> --> retourne les coordonnees\n\t\t\t\td une ville donnee\n");			 	
				printf("________________________________________________________________________________\n");

            	int choix_s;
					
				do
				{			
      				printf("\nTaper votre choix 1, 2, 3 ou 4 pour executer un sous programme 5 pour \nretourner au menu principale ou 0 pour quitter :\n\n-->\t");
                    scanf("%d", &choix_s);
                    fflush(stdin); 	
                }while(choix_s<0 || choix_s>5);							

                
                switch(choix_s)
                {				
				     case 1 :
				     {
						// Programme3.1 <VilleLaPlusPeuplee>
						system("cls");   							
                		printf("\nVilleLaPlusPeuplee\n");
						printf("______________________\n\n");				     	
						
				     	TriDecroissant(C);
				     	printf("\n\t Le nom de la ville la plus peuplee est : \t--> %s",C->TVilles[0].nom);
				     	printf("\n\t Nombre de la population de cette ville est : \t--> %d\n",C->TVilles[0].nbHabitants);
			            fflush(stdin);

				        char reponse;
							
						do
						{		    
	     					printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		        scanf("%c", &reponse);
	    		            fflush(stdin);       
						}while((reponse!='m')&&(reponse!='p')&&(reponse!='q'));				        
			    
					    if(reponse=='m')
					       goto menu1;
					       else if(reponse == 'p')
					         goto menu_p;
					         else if(reponse=='q')
					         exit(0);				     	
					 }break;
					 
					 
					 case 2 :
					 {
						// Programme3.2 <Les5VillesLesMoinsPeuplees>
						system("cls");   							
                		printf("\nLes5VillesLesMoinsPeuplees\n");
						printf("______________________\n\n");	
											 	
				     	TriCroissant(C);
				     	
						if(C->NVilles<5)
						{
							printf("\n\t Il existe sur la carte seulement %d villes ordonnees commme suit : \n-->", C->NVilles);
							for(int i =0; i<C->NVilles ; i++)
							{
								printf("\n\t %d : %s \t--> Nombre d habitant : %d \n", i+1, C->TVilles[i].nom, C->TVilles[i].nbHabitants);
							}
						}
   						
   						else
   						{
							printf("\n\t Les cinqs villes sur la carte qui sont les moins peuplees sont : \n\t-->");   							
   							for(int i =0; i<5 ; i++)
							{
								printf("\n\t %d : %s \t--> Nombre d habitant : %d \n ", i+1, C->TVilles[i].nom, C->TVilles[i].nbHabitants);
							}	
						}
					 	
				        char reponse;
							
						do
						{		    
	     					printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		        scanf("%c", &reponse);
	    		            fflush(stdin);       
						}while((reponse!='m')&&(reponse!='p')&&(reponse!='q'));				        
			    
					    if(reponse=='m')
					       goto menu1;
					       else if(reponse == 'p')
					         goto menu_p;
					         else if(reponse=='q')
					         exit(0);				     	
					 }break;
					 
					 
					 case 3 :
					 {
					   // Programme3.3 <DistanceVilles>
					   system("cls");   							
                	   printf("\ndistancesVilles\n");
					   printf("________________\n\n");
					   
					   float T1[2]; 	
					   float T2[2];
			
			           char *nom=(char *)malloc(sizeof(nom));	   
					   printf("\n\t Donner nom d'une ville sur la carte\n\t\t -->\t");
					   scanf("%[^\n]s",nom);
	    		       fflush(stdin);    		 	
     				   
					   char *nom_plus=(char *)malloc(sizeof(nom_plus));
					   printf("\n\t Donner nom d'une ville sur la carte\n\t\t -->\t");
					   scanf("%[^\n]s",nom_plus);
	    		       fflush(stdin);   
		               printf("\nTaper une touche pour continuer\n");					    		
					   getch();
					   
					 	if((RechercheCoordonnees(C, nom,T1)==1) && (RechercheCoordonnees(C, nom_plus,T2)==1))
					 	{
					 		float dis = sqrt(pow((T2[0]-T1[0]),2) + pow((T2[1]-T1[1]),2));
 		                    printf("\n\t La distance entre les deux villes %s - %s  est : --> %f\t\n", nom, nom_plus, dis );
						}	
						
						else
						{
						    printf("\n\t Une des deux villes ou les deux est/sont inexistant/s sur la carte\n\t veuillez verifier les villes cherchees\n");	
						}				   
					   		
				        char reponse;
							
						do
						{		    
	     					printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		        scanf("%c", &reponse);
	    		            fflush(stdin);       
						}while((reponse!='m')&&(reponse!='p')&&(reponse!='q'));				        
			    
					    if(reponse=='m')
					       goto menu1;
					       else if(reponse == 'p')
					         goto menu_p;
					         else if(reponse=='q')
					         exit(0);								    						
					 }break;
					 
					 
					 case 4 :
					 {
					    	// Programme3.4 <RechercheCoordonnees>
						    system("cls");   							
                	    	printf("\nCoordonneesVilles\n");
					    	printf("______________________\n\n");					 	

				            float T[2];
				            char *nom=(char *)malloc(sizeof(nom));
							printf("\n\tDonner le nom de la ville a chercher ses coordonnees :\n\t\t -->\t");
					 	    scanf("%[^\n]s",nom);
		             	    printf("\nTaper une touche pour continuer\n");					 	    
		             	    getch();	

			    	        
					 		if(RechercheCoordonnees(C, nom,T)==1)
					 		{
					  		printf("\n\t Ville trouvee et ses coordonnees sont :");
  	                    	printf("\n\t Latitude : \t--> %.3f", T[0]);
  	                    	printf("\n\t Longitude : \t--> %.3f \n", T[1]);  		
						    }
						    
						    else
						    {
							 printf("\n\t Ville non trouvee sur la carte \n");
							}


				        char reponse;
							
						do
						{		    
	     					printf("\nTaper m pour retourner au menu de ce programme ou p pour retourner au\nmenu principale, q pour quitter\n-->\t");
		    		        scanf("%c", &reponse);
	    		            fflush(stdin);       
						}while((reponse!='m')&&(reponse!='p')&&(reponse!='q'));				        
			    
					    if(reponse=='m')
					       goto menu1;
					       else if(reponse == 'p')
					         goto menu_p;
					         else if(reponse=='q')
					         exit(0);							
					 }break;
					 
					 case 5 : goto menu_p;
					 case 0 :	exit(0);
			    }
			  		
			} break;
				
		case 0 :	exit(0);
			
			
    }
    
	 return 0;
 	
 }
