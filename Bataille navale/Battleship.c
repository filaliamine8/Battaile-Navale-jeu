#include "header.h"

bool Ajouter_bateau(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE] ,int mode , int num)
{
    if( mode == 1) // on va placer les bateaux manuellement
    {
        if (Direction == left)
        {
            if (col-navir < 0) // Verifier si le bateau ne sort pas de la grille
            {
                printf("\033[1;31mLe bateaux est trop long pour la direction left\033[0m\n");
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line][col-i] != 0) // verifier s'il ya un autre bateau ou non
                    {
                        printf("\033[1;31mCollision entre deux bateaux\033[0m\n");
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++) // placer le bateau en changant les valeurs par le numero de bateau
                {
                    matrice[line][col-i]=num+1;
                }
                printf("\033[1;32mMabrook !! Le Bateau est bien placée\033[0m\n");

            }
        }
        else if (Direction == right)
        {
            if ((SIZE-col)-navir < 0)
            {
                printf("\033[1;31mLe bateaux est trop long pour la direction right\033[0m\n");
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line][col+i] != 0)
                    {
                        printf("\033[1;31mCollision entre deux bateaux\033[0m\n");
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line][col+i]= num+1;
                }
                printf("\033[1;32mMabrook !! Le Bateau est bien placée\033[0m\n");

            }
        }
        else if (Direction == up)
        {
            if (line-navir < 0)
            {
                printf("\033[1;31mLe bateaux est trop long pour la direction up\033[0m\n");
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line-i][col] != 0)
                    {
                        printf("\033[1;31mCollision entre deux bateaux\033[0m\n");
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line-i][col]=num+1;
                }
                printf("\033[1;32mMabrook !! Le Bateau est bien placée\033[0m\n");

            }
        }
        else if (Direction == down)
        {
            if ((SIZE-line)-navir < 0)
            {
                printf("\033[1;31mLe bateaux est trop long pour la direction down\033[0m\n");
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line+i][col] != 0)
                    {
                        printf("\033[1;31mCollision entre deux bateaux\033[0m\n");
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line+i][col]= num+1;
                }
                printf("\033[1;32mMabrook !! Le Bateau est bien placée\033[0m\n");

            }
        }
        return true;
    }
    else // on va placer les bateaux automatiquemant
    {
            if (Direction == left)
        {
            if (col-navir < 0)
            {
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line][col-i] != 0)
                    {
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line][col-i]=num+1;
                }

            }
        }
        else if (Direction == right)
        {
            if ((SIZE-col)-navir < 0)
            {
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line][col+i] != 0)
                    {
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line][col+i]= num+1;
                }

            }
        }
        else if (Direction == up)
        {
            if (line-navir < 0)
            {
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line-i][col] != 0)
                    {
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line-i][col]=num+1;
                }

            }
        }
        else if (Direction == down)
        {
            if ((SIZE-line)-navir < 0)
            {
                return false;
            }else
            {
                for (int i = 0; i < navir; i++)
                {
                    if (matrice[line+i][col] != 0)
                    {
                        return false;
                    }
                }
                for (int i = 0; i < navir; i++)
                {
                    matrice[line+i][col]= num+1;
                }

            }
        }
        return true;
    }
}

void Empty(int matrice[SIZE][SIZE]) // remplire tous les cases des grilles par 0 c'est a dire c'est l'eau
{
    for (int line = 0; line < SIZE; line++){
        for (int colone = 0; colone < SIZE; colone++){
            matrice[line][colone] = WATHER;
        }
    }
}

void printmatrice(int matrice[SIZE][SIZE])
{

    // Affichage des indices de colonnes
    printf("    ");
    for (int j = 0; j < SIZE; j++) {
        printf("%3d ", j);
    }
    printf("\n");

    // Ligne de séparation
    printf("   +");
    for (int j = 0; j < SIZE; j++) {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        // Affichage de l'indice de ligne
        printf("%3d |", i);

        for (int j = 0; j < SIZE; j++) {
            if (matrice[i][j] == WATHER) {
                printf("\033[40m   \033[0m");  // Fond noir
            } else {
                printf("\033[47m   \033[0m");  // Fond blanc
            }

            // Ligne verticale entre les colonnes
            printf("|");
        }
        printf("\n");

        // Ligne de séparation entre chaque ligne
        printf("   +");
        for (int j = 0; j < SIZE; j++) {
            printf("----");
        }
        printf("\n");
    }
}

void Placer_bateaux(int matrice[SIZE][SIZE],int mode)
{
    int _Navir[Nbr] = {Porte_avions,Croiseur,Contre_torpilleur,Contre_torpilleur,Torpilleur}; // mettre les tailles de bateaux dans un tableau

    Empty(matrice); // initialiser la grille a l'eau

    for (int num = 0; num < Nbr; num++) // Parcourir le tableau
    {
        if (mode == 0) // mode manu
        {
            do
            {

                int line = rand()%SIZE; // entrer des valeurs aleatoirement
                int col = rand()%SIZE;// entrer des valeurs aleatoirement
                int Direction = rand()%4;// entrer des valeurs aleatoirement
                if (Ajouter_bateau(_Navir[num],line,Direction,col,matrice,mode,num)) // verifier l'emplacement de bateau
                {
                    break; //emplacement valide et bateau bien placé
                }

            } while (1);
              //aff

        }else  // mode auto
        {
            int line ;
            int col ;
            int Direction ;
            printf("\033[46mOn va placer le %i eme bateau\033[0m \n",num+1);// affichea l'utilisateur le numero de bateau à placer
            do
            {
                printmatrice(matrice);

                printf("Position X :");
                line=entrer_0_9();// Vérifier si la valeur est valide
                printf("Position Y :");
                col=entrer_0_9();// Vérifier si la valeur est valide

                do{
                    printf("Direction : left(0),right(1),up(2),down(3)\n");
                    scanf("%d",&Direction);
                    if(Direction <0 || Direction >=4)
                    {
                        printf("\033[1;31mChoix invalide ! \033[0m");
                    }
                }while (Direction <0 || Direction >=4);// Vérifier si la direction est valide

            } while (!Ajouter_bateau(_Navir[num],line,Direction,col,matrice,mode,num));// verifier l'emplacement de bateau

        }
    }
}

void print(BATTLESHIP *battaille)
{
    printf("\x1b[35;5m\n\033[3m");
    printf("------------------------------------------------------------------\n");
    printf("|                      Bataille navale                            |\n");
    printf("|                                                                 |\n");
    printf("|        Carte de %-14s         carte de %-14s  |\n",battaille->player1.nom,battaille->player2.nom);
    printf("------------------------------------------------------------------\n");
    printf("\x1b[0m");

    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){// ca pour le 1 joueur
            if (i==-1){  // ici on va afficher la numerotation des colones
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }
            }
            else{

                if (j==-1){
                    printf(" %d ", i ); // on va afficher la numerotation des lignes
                }
                else{
                    if (battaille->player1.Print[i][j]==WATHER){
                        printf("\033[40m   ");   // Changement de la couleur d'arrière-plan à noir
                        printf("\033[0m");
                    }
                    else if(battaille->player1.Print[i][j] == 1){
                        printf("\033[47m   ");   // Changement de la couleur d'arrière-plan à blanc
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[40m\033[31m O ");  // la case et deja jouee et tombee dans l'eau
                        printf("\033[0m");
                    }
                }
            }
        }
        for (int j = -1; j < SIZE; j++){// ca pour le 2 joueur
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }
            }
            else{

                if (j==-1){
                    printf("|%d|", i );
                }
                else{
                    if (battaille->player2.Print[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else if(battaille->player2.Print[i][j] == 1){
                        printf("\033[47m   ");
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[40m\033[31m O ");// la case et deja jouee et tombee dans l'eau
                        printf("\033[0m");
                    }
                }
            }
        }
        printf("|\n");
    }
    printf("------------------------------------------------------------------\n");
}

void printmaps(BATTLESHIP *battaille)
{
    printf("------------------------------------------------------------------\n");
    printf("|                             Maps                                |\n");
    printf("|                                                                 |\n");
    printf("|              %-23s         %-17s  |\n",battaille->player1.nom,battaille->player2.nom);
    printf("------------------------------------------------------------------\n");

    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){// ca pour le 1 joueur
            if (i==-1){  // ici on va afficher la numerotation des colones
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }
            }
            else{

                if (j==-1){
                    printf(" %d ", i );// ici on va afficher la numerotation des lignes
                }
                else{
                    if (battaille->player1.matrice[i][j]==WATHER){
                        printf("\033[40m   ");   // Changement de la couleur d'arrière-plan à noir
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[47m   ");   // Changement de la couleur d'arrière-plan à blanc
                        printf("\033[0m");
                    }
                }
            }
        }
        for (int j = -1; j < SIZE; j++){// ca pour le 2 joueur
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }
            }
            else{

                if (j==-1){
                    printf("|%d|", i );
                }
                else{
                    if (battaille->player2.matrice[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else {
                        printf("\033[47m   ");
                        printf("\033[0m");
                    }
                }
            }
        }
        printf("|\n");
    }
    printf("------------------------------------------------------------------\n");
}

void Joue(BATTLESHIP *battaille)
{
    char choix;
    char filePath[50];// pour le chemain d'enregistrement du partie
    print_accueil();
    printf ("\n\033[4mChoix :\033[0m");
    scanf("%c",&choix);

    switch (choix) {
        case '1': // ici on va creer une nouvelle partie
                    printf("\033[4mVoulez-vous jouer contre un humain(0) ou contre la machine(1)?\033[0m\n");
                    battaille->enemy=entrer_0_1(); // controler les valeurs saisies
                    printf("\033[4mVoulez-vous placer automatique les bateaux tape (0) ou non (1)?\033[0m\n");
                    battaille->Mode=entrer_0_1(); // controler les valeurs saisies

                printf("\033[4mDonnez un nom a votre partie:\033[0m\n");
                do{
                    scanf("%s",battaille->name);
                    snprintf(filePath, sizeof(filePath), "%s/%s.txt", "data", battaille->name);
                    if(access(filePath, F_OK) != -1) // verifier s'il est existe deja une autre partie poratnat ce nom
                    {
                        printf("\033[1;31mVeuillez choisir un autre nom, car il existe deja une partie portant ce nom .\033[0m\n");
                    }
                }while(access(filePath, F_OK) != -1);

                battaille->currentplayer = 1; // le 1 joueur va jouer en premier
                battaille->etat=0;

                printf("\033[4mNom du joueur 1 :\033[0m\n");
                scanf("%s",battaille->player1.nom);
                printf("\033[4mAge du joueur 1 :\033[0m\n");
                scanf("%d",&battaille->player1.age);
                battaille->player1.temps=0;
                battaille->player1.point = 0;

                Placer_bateaux(battaille->player1.matrice,battaille->Mode);
                printf("Voici votre emplacement finale de bateaux \n");
                printmatrice(battaille->player1.matrice);
                printf("\nAttendez 40 secondes pour continuer ");

                sleep(40); // attendre 40 secondes avant la disparition d el'ecran
                system("cls");

                if (battaille->enemy == humain) //ici contre un humain
                {
                        printf("\033[4mNom du joueur 2 :\n");
                        scanf("%s",battaille->player2.nom);
                        printf("Age du joueur 2 :\033[0m\n");
                        scanf("%d",&battaille->player2.age);
                        battaille->player2.point =0;
                        battaille->player2.temps=0;

                        Placer_bateaux(battaille->player2.matrice,battaille->Mode);
                        printf("Voici votre emplacement finale de bateaux \n");
                        printmatrice(battaille->player2.matrice);
                        printf("\nAttendez 40 secondes pour continuer ");

                        sleep(40); // attendre 40 secondes avant la disparition d el'ecran
                        system("cls");
                }
                else
                {       //ici contre la machine
                        strcpy(battaille->player2.nom , "Machine");
                        battaille->player2.temps=0;
                        battaille->player2.point =0;
                        printf("\033[4mVoulez-vous niveau facile (0) ou difficile (1) ?\033[0m\n");
                        int niveau = entrer_0_1();
                        if(niveau==0)
                        {
                            battaille->player2.age=0; //pour facile l'age d ela machine est 0
                        }
                        else
                        {
                            battaille->player2.age=20;//pour difficle l'age d ela machine est 20
                        }
                        Placer_bateaux(battaille->player2.matrice,0);// l'emplacement de la mùachin eest toujours auto
                }
                Empty(battaille->player1.Print);
                Empty(battaille->player2.Print);
                battaille->etat++;
                savepartie("data",battaille); // enregistrer les donnes entrés
                run(battaille); // commencer le jeu
                break;

        case '2': // ici on va continuer une partie
                printf("\033[4mEntrez le nom de la partie que vous souhaitez continuer : \n\033[0m");
                do{
                    scanf("%s",battaille->name);
                    snprintf(filePath, sizeof(filePath), "%s/%s.txt", "data", battaille->name); // determiner le chemain du partie
                    if(access(filePath, F_OK) == -1)
                    {
                        printf("\033[1;31mVeuillez choisir un autre nom, car il n'existe pas une partie portant ce nom .\033[0m\n");
                    }
                }while(access(filePath, F_OK) == -1);
                loadpartie("data", battaille->name, battaille);
                run(battaille);
                break;
        case '3':
                // ici on va revisualisez une partie
                printf("\033[4mEntrez le nom de la partie que vous souhaitez revisualiser : \033[0m\n");
                do{
                    scanf("%s",battaille->name);
                    snprintf(filePath, sizeof(filePath), "%s/%s.txt", "data", battaille->name); // determiner le chemain du partie
                    if(access(filePath, F_OK) == -1)
                    {
                        printf("\033[1;31mVeuillez choisir un autre nom, car il n'existe pas une partie portant ce nom .\033[0m\n");
                    }
                }while(access(filePath, F_OK) == -1);
                revisualiser_partie("data", battaille->name, battaille);

                break;
        case '4':
            // ici on va affichier stastique
            printf("\033[4mEntrez le nom de la partie que vous souhaitez savoir ses statistiques : \033[0m\n");
            do{
                    scanf("%s",battaille->name);
                    snprintf(filePath, sizeof(filePath), "%s/%s.txt", "data", battaille->name); // determiner le chemain du partie
                    if(access(filePath, F_OK) == -1)
                    {
                        printf("\033[1;31mVeuillez choisir un autre nom, car il n'existe pas une partie portant ce nom .\033[0m\n");
                    }
                }while(access(filePath, F_OK) == -1);
                loadpartie("data", battaille->name, battaille);
                statistique(battaille);
            break;
        case '5':
            besoinAideBatailleNavale();
            break;
        case '6':
            printf("\033[1;34mAu revoir a bientot.\033[0m\n");
            break;
        default:
            printf("\033[1;31mOption non valide.\033[0m\n");
    }
}

bool winplayer_i(PlayerInfo player_j)
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){  // parcourir tout les cases de matrice
            if (player_j.matrice[i][j]!= WATHER){
                return false;
            }
        }
    }
    return true;
}

void tirerMachine(BATTLESHIP *battaille)
{
    int x = -1, y = -1;
    // Chercher une case non encore explorée à proximité d'un tir réussi
    if(battaille->player2.age==20)// niveau difficule
    {
        for (int i = 0; i < SIZE && x == -1; i++) {
            for (int j = 0; j < SIZE && x == -1; j++) {
                if (battaille->player1.Print[i][j] == 1) {
                    // Tirer autour de la dernière position réussie
                    for (int k = -1; k <= 1 && x == -1; k++) {
                        for (int l = -1; l <= 1 && x == -1; l++) {
                            int newX = i + k;
                            int newY = j + l;
                            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && battaille->player1.Print[newX][newY] == WATHER) {
                                x = newX;
                                y = newY;
                            }
                        }
                    }
                }
            }
        }

        // Si aucune case n'a été trouvée à proximité des tirs réussis, tirer au hasard
        if (x == -1) {
            do {
                x = rand() % SIZE;
                y = rand() % SIZE;
            } while (battaille->player1.Print[x][y] != WATHER);
        }
    }
    else
    { // c'est pour le niveau facile on va tirer aleatoi
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (battaille->player1.Print[x][y] != WATHER);
    }


    // Effectuer le tir
    if (battaille->player1.matrice[x][y] != WATHER) {
        battaille->player1.Print[x][y] = 1; // Touché
        battaille->player1.matrice[x][y] = WATHER;
        if (winplayer_i(battaille->player1))
        {
            battaille->player2.point+=1;
            printf("%s a gagnee",battaille->player2.nom);
            battaille->etat++;
            savepartie("data",battaille);
            exit(0); // la partie est terminee
        }
    tirerMachine(battaille);
    } else {
        if (battaille->player1.Print[x][y]==WATHER)
        {
            battaille->player1.Print[x][y] = -1; // Raté
        }
    }
}

void tirer_joueur_1(BATTLESHIP *battaille)
{
        int x;
        int y;
        //printmaps(battaille);
        print(battaille);
        printf("\033[46mC'est a %s de jouer\033[0m\n",battaille->player1.nom);
        clock_t start_time = clock();
        double cpu_time_used;

        do{
                printf("Position X :");
                x=entrer_0_9();
                printf("Position Y :");
                y=entrer_0_9();

                if(battaille->player2.Print[x][y]!=WATHER)
                {
                    printf("\033[1;31mVous avez deja toucher cet case , Resussisez ! \033[0m\n");
                }

                clock_t end_time = clock();
                cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // calculer le temps

        }while(battaille->player2.Print[x][y]!=WATHER && cpu_time_used<60); // controler le temps

        battaille->player1.temps+=cpu_time_used; // mise a jour de variable temps

        if(cpu_time_used<60)
        {

                    if (battaille->player2.matrice[x][y] != WATHER)//player 2 est touche
                    {

                        if(count_occurrence(battaille->player2.matrice,battaille->player2.matrice[x][y])==1) //si touché-coulé
                        {
                            printf("\033[1;32m Touche-coule\n\033[0m\n");
                        }
                        else
                        {
                            printf("\033[1;32m Touche\n\033[0m\n");
                        }
                        battaille->player2.matrice[x][y]= WATHER; //
                        battaille->player2.Print[x][y]= 1; // affecter le valeur 1 pour dire que le bateau est touche
                        battaille->etat++;
                        savepartie("data",battaille);

                        if (winplayer_i(battaille->player2))   //le player un gagne
                            {
                                battaille->player1.point+=1;
                                printf("%s a gagnee",battaille->player1.nom);
                                battaille->etat++;
                                savepartie("data",battaille);
                                exit(0); // la partie est terminee
                            }
                        tirer_joueur_1(battaille); // rejouer un eautre fois
                    }else
                    {
                        battaille->player2.Print[x][y] = -1; // Raté
                    }
        }
        else
        {
                    printf("\033[1;31mMalheureusement vous avez depasse le temps limitee \033[0m\n");
        }

        battaille->etat++;
        battaille->currentplayer=2;
        savepartie("data",battaille);

}

void tirer_joueur_2(BATTLESHIP *battaille)
{
        int x;
        int y;
        if (battaille->enemy == humain) // contre humain
        {
                //printmaps(battaille);
                print(battaille);
                printf("\033[46mC'est a %s de jouer\033[0m\n",battaille->player2.nom);
                clock_t start_time = clock();
                double cpu_time_used;

                do{

                    printf("Position X :");
                    x=entrer_0_9();
                    printf("Position Y :");
                    y=entrer_0_9();


                    if(battaille->player1.Print[x][y]!=WATHER)
                    {
                        printf("\033[1;31mVous avez deja toucher cet case , Resussisez ! \033[0m\n");
                    }
                    clock_t end_time = clock();
                    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

                }while(battaille->player1.Print[x][y]!=WATHER && cpu_time_used<60 );

                battaille->player2.temps+=cpu_time_used;

                if(cpu_time_used<60)
                {

                            if (battaille->player1.matrice[x][y] != WATHER)
                            {
                                //player 1 est touche

                                if(count_occurrence(battaille->player1.matrice,battaille->player1.matrice[x][y])==1)
                                {
                                    printf("\033[1;32m Touche-coule\n\033[0m\n");
                                }
                                else
                                {
                                    printf("\033[1;32m Touche\n\033[0m\n");
                                }
                                battaille->player1.matrice[x][y]= WATHER;
                                battaille->player1.Print[x][y]= 1;
                                battaille->etat++;
                                savepartie("data",battaille);

                                if (winplayer_i(battaille->player1))
                                {
                                    battaille->player2.point+=1;
                                    printf("%s a gagne\n",battaille->player2.nom);
                                    battaille->etat++;
                                    savepartie("data",battaille);
                                    exit(0); // la partie est terminee
                                }
                                tirer_joueur_2(battaille);// rejouer une autre fois
                            }
                            else
                            {
                                    battaille->player1.Print[x][y] = -1; // Raté
                            }
                }
                else
                {
                            printf("\n\033[1;31mMalheureusement vous avez depasse le temps limitee \033[0m\n");
                }

        }else // contre la machine
        {
            tirerMachine(battaille);
        }

        battaille->etat++;
        battaille->currentplayer=1;
        savepartie("data",battaille);

}

void run(BATTLESHIP *battaille)
{

    while (!winplayer_i(battaille->player1) && !winplayer_i(battaille->player2))
    {

        if(battaille->currentplayer==1)
        {
            tirer_joueur_1(battaille);
            tirer_joueur_2(battaille);
        }
        else
        {
            tirer_joueur_2(battaille);
            tirer_joueur_1(battaille);
        }

    }

    if (winplayer_i(battaille->player2))   //le player 1 gagne
    {
        printf("%s a gagne\n",battaille->player1.nom);
        exit(0);

    }else
    {
        printf("%s a gagne\n",battaille->player2.nom);
        exit(0);
    }
}

void statistique(BATTLESHIP *bataille)
{
    int tirsExacts1 = count_occurrence(bataille->player2.Print, 1);// calculer le nombre de tirs exacte pour 1
    int fautes1 = count_occurrence(bataille->player2.Print, -1);// calculer le nombre de tirs faut pour 1
    int tirsExacts2 = count_occurrence(bataille->player1.Print, 1);// calculer le nombre de tirs exacte pour 2
    int fautes2 = count_occurrence(bataille->player1.Print, -1); // calculer le nombre de tirs faut pour 2


    if (bataille->player1.point==0 && bataille->player2.point == 0)
    {
        printf("La partie n'est pas encore terminee .\n");
    }
    else
    {
        if (bataille->player1.point!=0)
        {
            printf("La partie est terminee et %s a gagne .\n", bataille->player1.nom);
        }
        else
        {
            printf("La partie est terminee et %s a gagne .\n", bataille->player2.nom);
        }
    }

    printf("              ---------------------------------------------------\n");
    printf("              | Joueur 1 : %-9s|    Joueur 2 : %-12s|\n", bataille->player1.nom, bataille->player2.nom);
    printf("|-------------|---------------------|---------------------------|\n");
    printf("|    Temps    |       %-14lf|       %-13lf       |\n", bataille->player1.temps, bataille->player2.temps);
    printf("| Tirs exacts |       %-14d|       %-13d       |\n", tirsExacts1, tirsExacts2);
    printf("| Tirs faux   |       %-14d|       %-13d       |\n", fautes1, fautes2);
    printf("-----------------------------------------------------------------\n");
}

int count_occurrence(int matrice[SIZE][SIZE],int i)//fonction qui permet de retouner les nombres de cases restants d'un bateau
{

    int nb=0;
    for (int line = 0; line < SIZE; line++){
        for (int colone = 0; colone < SIZE; colone++){
            if(matrice[line][colone]== i)
            {
                nb++;
            }
        }
    }
    return nb;
}
void print_accueil()
{
    printf("\x1b[35;5m\n\033[3m           |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("           |||||||                                                       |||||||\n");
    printf("           |||||||                                                       |||||||\n");
    printf("           |||||||                  BATAILLE NAVALE                      |||||||\n");
    printf("           |||||||                                                       |||||||\n");
    printf("           |||||||                                                       |||||||\n");
    printf("           |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n\n\n\x1b[34;5m\n\033[3m                                °           \n");
    printf("                                       °   \n");
    printf("                                            °   \n");
    printf("                                           | |     \n");
    printf("                                           | |     \n");
    printf("                                      )_)  )_)  )_)\n");
    printf("                                    )___))___))___)\\ \n");
    printf("                                  )____)____)_____)\\\\ \n");
    printf("                                _________________\\\\\\\\\n");
    printf("                    --------------\\                   /---------------\n");
    printf("                    \\ ^^^^^ ^^^^^^^^      ^^^^^^           ^^^^^^^    /\n");
    printf("                     \\  ^^^^      ^^^^     ^^^    ^^                 /\n");
    printf("                      \\     ^^^^      ^^^         ^^^      ^^^      /\n");
    printf("    ~     ~   ~        \\     ^^^^      ^^^         ^^^      ^^^    /     ~    ~      ~\n");
    printf("      ~           ~      ------------------------------------------- ~       ~     ~\n");
    printf("         ~        ~                   ~         ~         ~             ~        ~    ~  \n");
    printf("   ~        ~                   ~         ~         ~             ~         ~      ~\n");
    printf("\x1b[0m");
    printf("\n                      Cliquez sur entrer pour acceder au menu principale ");
    scanf("%*c");
    system("cls");
    printf ("\033[3m                                  \033[4mMenu principale:\n\n\033[0m                                1. Nouvelle Partie\n                              2. Reprendre le Combat\n                              3. Revisualiser Partie\n                           4. Consultez des Statistiques\n                                 5. Besoin d'Aide?\n                                    6. Quitter\n\n");


}
void Changer_etat(const char *nomFichier, const BATTLESHIP *bataille)
{
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    FILE *fichierTemp = fopen("temp.txt", "w"); // Creer un fichier temporaire pour écrire les mises a jour
    if (fichierTemp == NULL) {
        perror("Erreur lors de la création du fichier temporaire");
        fclose(fichier);
        return;
    }
    // Déclaration des variables necessaires
    char ligne[256];
    int Point1Trouve = 0 , Point2Trouve =0;
    int etatTrouve = 0, joueurTrouve = 0, tempsPlayer1Trouve = 0 ,tempsPlayer2Trouve = 0;

    // Lecture de chaque ligne du fichier jusqu'à la fin du fichier
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char *positionMotifPoint1 = strstr(ligne, "PointPlayer1 : ");
        char *positionMotifPoint2 = strstr(ligne, "PointPlayer2 : ");
        char *positionMotifJoueur = strstr(ligne, "joueurCourant : ");
        char *positionMotifEtat = strstr(ligne, "Etat : ");
        char *positionMotifTempsPlayer1 = strstr(ligne, "TempsPlayer1 : ");
        char *positionMotifTempsPlayer2 = strstr(ligne, "TempsPlayer2 : ");

        // Mise à jour des variables si ils sont trouvées sinon on recopie la ligne telle quelle dans le fichier temporaire
        if (!Point1Trouve && positionMotifPoint1 != NULL) {
            int offset = positionMotifPoint1 - ligne + strlen("PointPlayer1 : ");
            fprintf(fichierTemp, "%.*s%d\n", offset, ligne, bataille->player1.point);
            Point1Trouve = 1;
        } else if (!Point2Trouve && positionMotifPoint2 != NULL) {
            int offset = positionMotifPoint2 - ligne + strlen("PointPlayer2 : ");
            fprintf(fichierTemp, "%.*s%d\n", offset, ligne, bataille->player2.point);
            Point2Trouve = 1;
        }else if (!joueurTrouve && positionMotifJoueur != NULL) {
            int offset = positionMotifJoueur - ligne + strlen("joueurCourant : ");
            fprintf(fichierTemp, "%.*s%d\n", offset, ligne, bataille->currentplayer);
            joueurTrouve = 1;
        } else if (!etatTrouve && positionMotifEtat != NULL) {
            int offset = positionMotifEtat - ligne + strlen("Etat : ");
            fprintf(fichierTemp, "%.*s%d\n", offset, ligne, bataille->etat);
            etatTrouve = 1;
        } else if (!tempsPlayer1Trouve && positionMotifTempsPlayer1 != NULL) {
            int offset = positionMotifTempsPlayer1 - ligne + strlen("TempsPlayer1 : ");
            fprintf(fichierTemp, "%.*s%lf\n", offset, ligne, bataille->player1.temps);
            tempsPlayer1Trouve = 1;
        } else if (!tempsPlayer2Trouve && positionMotifTempsPlayer2 != NULL) {
            int offset = positionMotifTempsPlayer2 - ligne + strlen("TempsPlayer2 : ");
            fprintf(fichierTemp, "%.*s%lf\n", offset, ligne, bataille->player2.temps);
            tempsPlayer2Trouve = 1;
        }else {
            fprintf(fichierTemp, "%s", ligne);
        }
    }

    fclose(fichier);
    fclose(fichierTemp);

    // Suppression du fichier original
    if (remove(nomFichier) != 0) {
        perror("Erreur lors de la suppression du fichier original");
        return;
    }

    // Renommage du fichier temporaire pour remplacer le fichier original
    if (rename("temp.txt", nomFichier) != 0) {
        perror("Erreur lors du renommage du fichier temporaire");
        return;
    }
}

void savepartie(char *folderPath, const BATTLESHIP *battaille)
{
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s.txt", folderPath, battaille->name);

    FILE *file = fopen(filePath, "a"); // "a" pour qu'on peut ajouter

    if (file) {

        // Continuer à ajouter les autres informations dans le fichier
        fprintf(file, "NomPartie : %s\n", battaille->name);
        fprintf(file, "NomPlayer1 : %s\n", battaille->player1.nom);
        fprintf(file, "NomPlayer2 : %s\n", battaille->player2.nom);
        fprintf(file, "AgePlayer1 : %d\n", battaille->player1.age);
        fprintf(file, "AgePlayer2 : %d\n", battaille->player2.age);
        fprintf(file, "PointPlayer1 : %d\n", battaille->player1.point);
        fprintf(file, "PointPlayer2 : %d\n", battaille->player2.point);
        fprintf(file, "joueurCourant : %d\n", battaille->currentplayer);
        fprintf(file, "Mode : %d\n", battaille->Mode);
        fprintf(file, "Enemies : %d\n", battaille->enemy);
        fprintf(file, "Etat : %d\n", battaille->etat);
        fprintf(file, "TempsPlayer1 : %lf\n", battaille->player1.temps);
        fprintf(file, "TempsPlayer2 : %lf\n", battaille->player2.temps);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                fprintf(file, "p1m(%d)[%d][%d] : %d\n",battaille->etat, i, j, battaille->player1.matrice[i][j]);
                fprintf(file, "p1p(%d)[%d][%d] : %d\n",battaille->etat, i, j, battaille->player1.Print[i][j]);
                fprintf(file, "p2m(%d)[%d][%d] : %d\n",battaille->etat, i, j, battaille->player2.matrice[i][j]);
                fprintf(file, "p2p(%d)[%d][%d] : %d\n", battaille->etat, i, j, battaille->player2.Print[i][j]);
            }
        }

        // Fermer le fichier
        fclose(file);
        Changer_etat(filePath, battaille);

    } else {
        perror("Erreur lors de l'ouverture du fichier pour enregistrement");
    }
}

int revisualiser_partie(const char *folderPath, const char *gameName, BATTLESHIP *battaille)
{
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s.txt", folderPath, gameName);
    FILE *file = fopen(filePath, "r");
    fseek(file, 0, SEEK_SET);

    if (file) {

        fscanf(file, "NomPartie : %s\n", battaille->name);
        fscanf(file, "NomPlayer1 : %s\n", battaille->player1.nom);
        fscanf(file, "NomPlayer2 : %s\n", battaille->player2.nom);
        fscanf(file, "AgePlayer1 : %d\n", &battaille->player1.age);
        fscanf(file, "AgePlayer2 : %d\n", &battaille->player2.age);
        fscanf(file, "PointPlayer1 : %d\n", &battaille->player1.point);
        fscanf(file, "PointPlayer2 : %d\n", &battaille->player2.point);
        fscanf(file, "joueurCourant : %d\n", &battaille->currentplayer);
        fscanf(file, "Mode : %d\n", &battaille->Mode);
        fscanf(file, "Enemies : %d\n", &battaille->enemy);
        fscanf(file, "Etat : %d\n", &(battaille->etat));
        fscanf(file, "TempsPlayer1 : %lf\n", &battaille->player1.temps);
        fscanf(file, "TempsPlayer2 : %lf\n", &battaille->player2.temps);

                int etat_actuelle  = 1;
                int compteurLigne = 1;  // Compteur de lignes
                char ligne[256];  // Taille maximale d'une ligne

                do {

                    for (int i = 0; i < SIZE; i++) {
                        for (int j = 0; j < SIZE; j++) {
                            fscanf(file, "p1m(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player1.matrice[i][j]);
                            fscanf(file, "p1p(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player1.Print[i][j]);
                            fscanf(file, "p2m(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player2.matrice[i][j]);
                            fscanf(file, "p2p(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player2.Print[i][j]);
                            compteurLigne+=4;
                        }
                    }
                    printf("Etat : %d\n", etat_actuelle);
                    print(battaille);
                    while (fgets(ligne, sizeof(ligne), file) != NULL && compteurLigne <= 412*etat_actuelle) { // pour chaque etat il ya 412 ligne
                    compteurLigne++;
                    }
                    etat_actuelle++;
                } while (etat_actuelle < battaille->etat+1);

        // Revenez au début du fichier
        fseek(file, 0, SEEK_SET);
        fclose(file);
        return 1;  // La lecture a réussi
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement.\n");
        return 0;  // La lecture a échoué
    }
}

int loadpartie(const char *folderPath, const char *gameName, BATTLESHIP *battaille)
{
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s.txt", folderPath, gameName);
    FILE *file = fopen(filePath, "r");
    fseek(file, 0, SEEK_SET);

    if (file) {

        fscanf(file, "NomPartie : %s\n", battaille->name);
        fscanf(file, "NomPlayer1 : %s\n", battaille->player1.nom);
        fscanf(file, "NomPlayer2 : %s\n", battaille->player2.nom);
        fscanf(file, "AgePlayer1 : %d\n", &battaille->player1.age);
        fscanf(file, "AgePlayer2 : %d\n", &battaille->player2.age);
        fscanf(file, "PointPlayer1 : %d\n", &battaille->player1.point);
        fscanf(file, "PointPlayer2 : %d\n", &battaille->player2.point);
        fscanf(file, "joueurCourant : %d\n", &battaille->currentplayer);
        fscanf(file, "Mode : %d\n", &battaille->Mode);
        fscanf(file, "Enemies : %d\n", &battaille->enemy);
        fscanf(file, "Etat : %d\n", &(battaille->etat));
        fscanf(file, "TempsPlayer1 : %lf\n", &battaille->player1.temps);
        fscanf(file, "TempsPlayer2 : %lf\n", &battaille->player2.temps);

                int etat_actuelle  = 1;
                int compteurLigne = 1;  // Compteur de lignes
                char ligne[256];  // Taille maximale d'une ligne

                do {

                    for (int i = 0; i < SIZE; i++) {
                        for (int j = 0; j < SIZE; j++) {
                            fscanf(file, "p1m(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player1.matrice[i][j]);
                            fscanf(file, "p1p(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player1.Print[i][j]);
                            fscanf(file, "p2m(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player2.matrice[i][j]);
                            fscanf(file, "p2p(%d)[%d][%d] : %d\n", &etat_actuelle, &i, &j, &battaille->player2.Print[i][j]);
                            compteurLigne+=4;
                        }
                    }
                    while (fgets(ligne, sizeof(ligne), file) != NULL && compteurLigne <= 412*etat_actuelle) {
                    compteurLigne++;
                    }
                    etat_actuelle++;
                } while (etat_actuelle < battaille->etat+1);

        // Revenez au début du fichier
        fseek(file, 0, SEEK_SET);
        fclose(file);
        return 1;  // La lecture a réussi
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement.\n");
        return 0;  // La lecture a échoué
    }
}

void besoinAideBatailleNavale()
{
    printf("\n\033[33mRegles d'Interface :\n\033[0m");
    printf("Les instructions a l'ecran doivent etre suivies scrupuleusement par les joueurs.\n");
    printf("Toute erreur de saisie des coordonnees interrompra la sequence de jeu actuelle.\n\n");

    printf("\033[33mJoueurs et Configuration :\n\033[0m");
    printf("Deux adversaires s'affrontent, avec pour chacun deux grilles de format 10x10.\n");
    printf("Chaque grille a ses lignes et ses colonnes numerotees de 1 a 10.\n\n");

    printf("\033[33mFlotte :\n\033[0m");
    printf("Chaque joueur controle :\n");
    printf("1 Porte-avions (occupant 5 cases)\n");
    printf("1 Croiseur (occupant 4 cases)\n");
    printf("2 Contre-torpilleurs (occupant 3 cases chacun)\n");
    printf("1 Torpilleur (occupant 2 cases)\n\n");

    printf("\033[33mPlacement des Bateaux :\n\033[0m");
    printf("Les bateaux sont disposes sur la grille par les joueurs.\n");
    printf("Les joueurs peuvent opter pour un placement aleatoire ou manuel de leur flotte.\n");
    printf("La regle d'or est l'interdiction pour les bateaux d etre en superposition les uns aux autres.\n");
    printf("L'ordre de placement suit une hierarchie basee sur la taille, allant du plus grand au plus petit navire.\n\n");

    printf("\033[33mSelection de la Direction :\n\033[0m");
    printf("Lors du placement manuel, apres avoir determine la position initiale du navire, les joueurs indiqueront la direction en utilisant les codes numeriques suivants :\n");
    printf("0 pour Left (Gauche)\n");
    printf("1 pour Right (Droite)\n");
    printf("2 pour Up (Haut)\n");
    printf("3 pour Down (Bas)\n");
    printf("Ces codes determinent l'orientation que prendront les navires a partir de leur point de depart sur la grille.\n\n");

    printf("\033[33mModes de Jeu :\n\033[0m");
    printf("Joueur contre Joueur : Alternance de tours pour deux joueurs.\n");
    printf("Joueur contre Machine : Un joueur humain s'oppose a la machine .\n\n");

    printf("\033[33mInstructions de Jeu :\n\033[0m");
    printf("A chaque tour , ");
    printf("entrer les coordonnees de la grille ou le joueur suspecte la presence d'un navire ennemi.\n");
    printf("Si un navire est touche mais pas coule, on affiche \"touche\", et la case est coloree en blanc.\n");
    printf("Le joueur qui a reussi a toucher un navire ennemi a droit a un autre tour.\n");
    printf("Si le navire est coule, on affiche \"touche coule\", et toutes les cases occupees par le navire sont colorees en blanc.\n");
    printf("Si aucun navire n'est touche, on place un \"O\" rouge sur la case attaquee et le tour passe a l'adversaire.\n");
    printf("Il n'est pas possible de jouer sur une case qui a deja ete ciblee lors d'un tour precedent, que ce soit avec un \"O\" rouge, un \"touche\" ou un \"touche coule\".\n\n");

    printf("\033[33mContrainte Temporelle :\n\033[0m");
    printf("Les joueurs disposent d'une minute maximum pour proceder a une attaque.\n");
    printf("Le non-respect de cette limite temporelle conduit a l'abandon du tour a l'adversaire ou a l'ordinateur.\n\n");

    printf("\033[33mSauvegarde et Statistiques :\n\033[0m");
    printf("Chaque partie est systematiquement enregistree, donnant ainsi la possibilite de reprendre une session interrompue ou de la revisualiser ainsi que de consulter les statistiques relatives aux parties precedentes.\n");
}
int entrer_0_9()
{
    int x;
    do{
        scanf("%d",&x);
        if( (x>9)||(x<0) )
        {
            printf("\033[1;31mIl doit etre entre 0 et 9 .\033[0m Resussisez: ");
        }
    }while( (x>9)||(x<0) );
    return x;
}
int entrer_0_1()
{
    int i;
    do{
            scanf("%d",&i);
            if(i!=0&&i!=1)
            {
                    printf("\033[1;31mChoix invalide ! \033[0m Resussisez: ");
            }
    }while(i!=0&&i!=1);
    return i;
}
