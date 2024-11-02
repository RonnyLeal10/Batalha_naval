#include <iostream>
#include <stdlib.h>
#include <unistd.h> // Para a função sleep(dormir)
#include <cstdlib> // Para a função system(usado para limpar o terminal) e para sair do jogo
#include <string.h>
using namespace std;
const int tamanho=10;
void tabuleiro(string tab[tamanho][tamanho]);
void mostrarTab(string tab[tamanho][tamanho]);
void preenchimento(string tab[tamanho][tamanho], int tamanho_barco, int linha, int coluna, char direcao,string tipo_do_barco);
void mostrarTabelaAtualizado(string tab[tamanho][tamanho]);
bool Tiro( string tab[tamanho][tamanho],int linha , int coluna);
void TabelaAtualizaComTiros(string tab[tamanho][tamanho]);
bool BarcoAfundado(string tab[tamanho][tamanho], string tipoBarco);
int main(){
    string tabela1[10][10];
    string tabela2[tamanho][tamanho];
    int opcao,cont1=0,cont2=0;//Opcao é para escolha das opções logo no inicio do algoritmo; O cont é usado para saber se o jogador ja atingiu o número de preenchemento do barco
    int barco11,barco21,barco31,barco41,barco51,barco12,barco22,barco32,barco42,barco52;
     do{
        cout<<"Escolha uma das opções: "<<"\n1- Iniciar o jogo.\n2-Sair."<<endl;
     cin>>opcao;
     }while(opcao!=2 && opcao!=1);

            if(opcao==1){

            cout<<"A iniciar o jogo!!!"<<endl;
            sleep(3);
            cout<<"Está quase...";
            sleep(1);
            system("cls");//Serve para limapr o terminal.
            cout<<"Esta tabela vale para os dois jogadores. "<<endl;
            tabuleiro(tabela1);//Iniciar a tabela1
            tabuleiro(tabela2);//Iniciar a tabela2
            mostrarTab(tabela1);//Como tabela é igual no inicio ,então é so preciso mostrar uma tabela que vale para os dois
            int l1,l2,c1,c2;
            char p;
            string b;
            for(int q=0;q<10;q++){//10 escolhas(5 para o primeiro jogador e o resto para o outro).
                    if((q%2)==0){//Determina o preenchimento altaternado dos jogadores.
                            cout<<"++++++++++++++++++++++++++++++ JOGADOR 1 +++++++++++++++++++++++++++++++"<<endl;//Para preenchemento do jogador 1.
                            cout<<"\n";
                            cout<<"Preencha 5 barcos de diferentes tamanhos na tabela!\n1 - Barco de dimensão 2!\n2 - Barco de dimensão 3!\n3 - Barco de dimensão 4!\n4 - Barco  de dimensão 3!\n5 - Barco de dimensão 5!"<<endl;
                            cout<<"Diga a linha e coluna que deseja preencher o barco "<<cont1+1<<endl;

                             do{
                                cout << "Informe a linha do seu preenchimento (entre 0 e 9): ";
                                cin >> l1;
                                if(l1<0 || l1 >=10){
                                cout<<"Erro: A linha tem que ser entre 0 e 9, mas conforme a dimensão do barco!!!."<<endl;
                            }
                            } while (l1 < -1 || l1 >= 10);

                            do {
                                cout << "Informe a coluna do seu preenchimento (entre 0 e 9): ";
                                cin >> c1;
                                if(c1<0 || c1 >=10){
                               cout<<"Erro: A coluna tem que ser entre 0 e 9, mas conforme a dimensão do barco!!!."<<endl;
                            }
                            } while (c1 < -1 || c1 >= 10);


                            do{
                            cout<<"Deseja na posição horizontal(h) ou vertical(v):";
                            cin>>p;
                        }while((p != 'h') && ( p != 'H') && ( p != 'v') && (p != 'V'));
                                if (cont1 == 0) {
                                    barco11 = 2;
                                    b = "B1";
                                    preenchimento(tabela1, barco11, l1, c1, p, b);
                                } else if (cont1 == 1) {
                                    barco21 = 3;
                                    b = "B2";
                                    preenchimento(tabela1, barco21, l1, c1, p, b);
                                } else if (cont1 == 2) {
                                    barco31 = 4;
                                    b = "B3";
                                    preenchimento(tabela1, barco31, l1, c1, p, b);
                                } else if (cont1 == 3) {
                                    barco41 = 3;
                                    b = "B4";
                                    preenchimento(tabela1, barco41, l1, c1, p, b);
                                } else if (cont1 == 4) {
                                    barco51 = 5;
                                    b = "B5";
                                    preenchimento(tabela1, barco51, l1, c1, p, b);
                                }
                            sleep(1);
                            cont1++;
                            system("cls");
                            mostrarTabelaAtualizado(tabela1);

                    }else{
                        char p;
                        cout<<"++++++++++++++++++++++++++++++ JOGADOR 2 +++++++++++++++++++++++++++++++"<<endl;//Para o preenchemento do jogador 2.
                        cout<<"\n";
                         cout<<"Preencha 5 barcos de diferentes tamanhos na tabela!\n1 - Barco de dimensão 2!\n2 - Barco de dimensão 3!\n3 - Barco de dimensão 4!\n4 - Barco  de dimensão 3!\n5 - Barco de dimensão 5!"<<endl;
                        cout<<"Diga a linha e coluna que deseja preencher o barco "<<cont2+1<<endl;
                        do {
                                cout << "Informe a linha do seu preenchimento (entre 0 e 9): ";
                                cin >> l2;
                                if(l2<0 || l2 >=10){
                                cout<<"Erro: A linha tem que ser entre 0 e 9, mas conforme a dimensão do barco!!!."<<endl;
                            }
                            } while (l2 < -1 || l2 >= 10);

                            do {
                                cout << "Informe a coluna do seu preenchimento (entre 0 e 9): ";
                                cin >> c2;
                                if(c2<0 || c2 >=10){
                               cout<<"Erro: A coluna tem que ser entre 0 e 9, mas conforme a dimensão do barco!!!."<<endl;
                                }
                            } while (c2 < -1 || c2 >= 10);
                            do{
                            cout<<"Deseja na posição horizontal(h) ou vertical(v):";
                            cin>>p;
                        }while((p!='h' && p!='H') && (p!='v' && p!='V'));
                                if (cont2 == 0) {
                                    barco12 = 2;
                                    b = "B1";
                                    preenchimento(tabela2, barco12, l2, c2, p, b);
                                } else if (cont2 == 1) {
                                    barco22 = 3;
                                    b = "B2";
                                    preenchimento(tabela2, barco22, l2, c2, p, b);
                                } else if (cont2 == 2) {
                                    barco32 = 4;
                                    b = "B3";
                                    preenchimento(tabela2, barco32, l2, c2, p, b);
                                } else if (cont2 == 3) {
                                    barco42 = 3;
                                    b = "B4";
                                    preenchimento(tabela2, barco42, l2, c2, p, b);
                                } else if (cont2 == 4) {
                                    barco52 = 5;
                                    b = "B5";
                                    preenchimento(tabela2, barco52, l2, c2, p, b);
                                }
                                sleep(1);

                               system("cls");
                               mostrarTabelaAtualizado(tabela2);

                               cont2++;

                    }
                    if(cont1==5){
                            cout<<"++++++++++++++++++++++++++++++ JOGADOR 1 +++++++++++++++++++++++++++++++ "<<endl;
                    mostrarTabelaAtualizado(tabela1);
                    }
                        cout<<"\n\n\n";
                    if(cont2==5){
                            cout<<"++++++++++++++++++++++++++++++ JOGADOR 2 +++++++++++++++++++++++++++++++"<<endl;
                    mostrarTabelaAtualizado(tabela2);
                    sleep(3);
                    }
            }
            sleep(5);
            cout<<"Enter!!!" <<system("Pause");
            system("cls");
            cout<<"           SE PREPARA..."<<endl;
            sleep(2);
            cout<<"       ESTÁ A COMEÇAR O JOGO"<<endl;
            sleep(3);
            system("cls");
            cout<<"++++++++++++++++++++++++++++++BATALHA NAVAL++++++++++++++++++++++++++++++ "<<endl;
            sleep(5);

cout<<"\n"<<endl;

            //Inicio das jogadas
            int jogador1,jogador2;
            int TiroLinha1,TiroColuna1,TiroColuna2,TiroLinha2;
            int ContJogador=0;//Determina que jogador é que tem jogar
            bool jogo=true;
            bool Analise=true;
            int verTabuleiro1=0,verTabuleiro2=0;
            int b11=0,b21=0,b31=0,b41=0,b51=0,b12=0,b22=0,b32=0,b42=0,b52=0;
            while(jogo==true){
                if((ContJogador%2)==0){
                    cout<<"++++++++++++++++++++++++++++++ JOGADOR 1 +++++++++++++++++++++++++++++++"<<endl;
                    TabelaAtualizaComTiros(tabela1);
                    int NumeroDeJogada=1;
                    while(NumeroDeJogada<=3){



                    do {
                        cout << "Que linha é que desejas atingir o adversario: ";
                        cin >> TiroLinha1;

                        cout << "Que coluna é que desejas atingir o adversario: ";
                        cin >> TiroColuna1;

                        if (TiroLinha1 < -1 || TiroLinha1 >= 10 || TiroColuna1 < -1 || TiroColuna1 >= 10) {//Verifica se a linha e a coluna pertencem a matriz
                            cout << "As coordenadas estão fora da matriz!!! Tenta novamente." << endl;
                            Analise = false;//Analise torna falso caso a linha ou coluna está fora da matriz
                        } else if (tabela2[TiroLinha1][TiroColuna1] == " " || tabela2[TiroLinha1][TiroColuna1] == "X") {//Verifica se não houve tiro no espaço escolhido
                            cout << "Já houve tiro neste espaço. Escolha outro espaço. Tenta novamente." << endl;
                            Analise = false;//Analise torna falso caso houver tiro no espaço escolhido
                            } else {
                                Analise = true;
                            }
                        } while (!Analise);//Se Analise for falso vai mandar repetir tudo outra vez ou seja o espaço que deseja atirar

                        if(Analise==true){
                        Tiro(tabela2,TiroLinha1,TiroColuna1);
                        }

                if(Analise==true){
                        NumeroDeJogada++;
                }


                    }

                        ContJogador++;

                    system("cls");
                    //Verificaçao do tabuleiro do jogador 2

                    for(int i=0;i<10;i++){
                        for(int j=0;j<10;j++){
                            if(tabela2[i][j]!="B1" && tabela2[i][j]!="B2" && tabela2[i][j]!="B3" && tabela2[i][j]!="B4" && tabela2[i][j]!="B5"){
                                verTabuleiro2++;
                        }
                    }
                }
                if(verTabuleiro2==83){//10*10=100;100-17=87; 17 é número de todas as partes do barco
                        jogo=false;
                    cout<<"+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^ PARABENSSSSS +*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^"<<endl;
                            cout<<"                                 A vitória é do JOGADOR 2                          "<<endl;
                }

            }else{
                cout<<"++++++++++++++++++++++++++++++ JOGADOR 2 +++++++++++++++++++++++++++++++"<<endl;
                TabelaAtualizaComTiros(tabela2);
                    int NumeroDeJogada2=1;
                    while(NumeroDeJogada2<=3){

                        //Tiro
                    do {
                        cout << "Que linha é que desejas atingir o adversario: ";
                        cin >> TiroLinha2;

                        cout << "Que coluna é que desejas atingir o adversario: ";
                        cin >> TiroColuna2;

                        if (TiroLinha2 < -1 || TiroLinha2 >= 10 || TiroColuna2 < -1 || TiroColuna2 >= 10) {//Verifica se a linha e a coluna pertencem a matriz
                            cout << "As coordenadas estão fora da matriz!!! Tenta novamente." << endl;//
                            Analise = false;//Analise torna falso caso a linha ou coluna está fora da matriz
                        } else if (tabela1[TiroLinha2][TiroColuna2] == " " || tabela1[TiroLinha2][TiroColuna2] == "X") {//Verifica se não houve tiro no espaço escolhido
                            cout << "Já houve tiro neste espaço. Escolha outro espaço. Tenta novamente." << endl;
                            Analise = false;//Analise torna falso caso houver tiro no espaço escolhido
                            } else{
                                Analise = true;
                            }

                        } while (!Analise);//Se Analise for falso vai mandar repetir tudo outra vez ou seja o espaço que deseja atirar
                        if(Analise==true){
                        Tiro(tabela1,TiroLinha2,TiroColuna2);
                        }
                        //Verificação da existencia do barco
                      // if (b12 == 2 && verificaBarcoAfundado(tabela1, "B1", 2)) {
                        //    cout << "Afundaste o barco 1 (B1)." << endl;
                        //}
                       // if (b22 == 3 && verificaBarcoAfundado(tabela1, "B2", 3)) {
                         //   cout << "Afundaste o barco 2 (B2)." << endl;
                       // }
                        //if (b32 == 4 && verificaBarcoAfundado(tabela1, "B3", 4)) {
                          //  cout << "Afundaste o barco 3 (B3)." << endl;
                        //}
                        //if (b42 == 3 && verificaBarcoAfundado(tabela1, "B4", 3)) {
                          //  cout << "Afundaste o barco 4 (B4)." << endl;
                        //}
                        //if (b52 == 5 && verificaBarcoAfundado(tabela1, "B5", 5)) {
                          //  cout << "Afundaste o barco 5 (B5)." << endl;
                        //}
                if(Analise==true){
                        NumeroDeJogada2++;
                }

                    }
                    system("cls");

                    ContJogador++;

                //Verificaçao do tabuleiro do jogador 1
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        if(tabela1[i][j]!="B1" && tabela1[i][j]!="B2" && tabela1[i][j]!="B3" && tabela1[i][j]!="B4" && tabela1[i][j]!="B5"){
                            verTabuleiro1++;
                        }
                    }
                }
                if(verTabuleiro1==83){
                    cout<<"+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^ PARABENSSSSS +*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^+*~^"<<endl;
                    cout<<"                                 A vitória é do JOGADOR 2                          "<<endl;
                }
            }

            }
        }


            if(opcao==2){
            sleep(1);
            cout<<"A sair do jogo..."<<endl;
            sleep(2);
            cout<<"Obrigado por jogar"<<endl;
            cout<<"\n\n\n\n\n\n\n\n";
            cout<<"                                                                   Siga a pagina para ficar a par das atualizações!!!"<<endl;
            sleep(5);
            exit(0);
            }



return 0;
}

void tabuleiro(string tab[tamanho][tamanho]){
    for(int linha=0;linha<10;linha++){
        for(int coluna=0;coluna<10;coluna++){
            tab[linha][coluna]="A";
        }
    }
}

void mostrarTab(string tab[tamanho][tamanho]){
    cout<<"     0     1     2     3     4     5     6     7     8    9  "<<endl;
    for(int linha=0;linha<tamanho;linha++){
            cout<<linha<<"  ";
            for(int coluna=0;coluna<tamanho;coluna++){
                cout<<"[ "<<tab[linha][coluna]<<" ] ";
                }
            cout<<"\n\n";
        }
    }

void preenchimento(string tab[tamanho][tamanho], int tamanho_barco, int linha, int coluna, char direcao, string tipo_do_barco) {
    bool posicaoValida = true;

    // Verificações gerais de posição
    if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho) {
        posicaoValida = false;
    }

    if (posicaoValida) {
        // Verificação de posição e preenchimento na horizontal
        if ((direcao == 'h' || direcao == 'H') && coluna + tamanho_barco - 1 < tamanho) {//Verifica se o barco cabe na linha introduzido pelo utilizador e se caber entra nesse loop
            for (int i = 0; i < tamanho_barco; i++) {
                if (coluna + i >= tamanho || tab[linha][coluna + i] != "A") {//Se o espço selecionado tiver barco , entra nesse loop
                    posicaoValida = false;////Caso a condição seja verdade , declara  a posicaValida em falso
                    break;//Depois para o programa e salta para onde a posiçao é invalida(no final dessa funçao)
                }
            }

            if (posicaoValida) {//No espaço introduzido pelo utilizador, não ha barco/s
                for (int i = 0; i < tamanho_barco; i++) {
                    tab[linha][coluna + i] = tipo_do_barco;
                }
            }
        }
        // Verificação de posição e preenchimento na vertical
        else if ((direcao == 'v' || direcao == 'V') && linha + tamanho_barco - 1 < tamanho) {//Verifica se o barco cabe na coluna introduzido pelo utilizador e se caber entra nesse loop
            for (int i = 0; i < tamanho_barco; i++) {
                if (linha + i >= tamanho || tab[linha + i][coluna] != "A") {
                    posicaoValida = false;
                    break;
                }
            }

            if (posicaoValida) {
                for (int i = 0; i < tamanho_barco; i++) {
                    tab[linha + i][coluna] = tipo_do_barco;
                }
            }
        }
        // Verificação de posição e preenchimento na horizontal (inversa)
        else if ((direcao == 'h' || direcao == 'H') && coluna + tamanho_barco - 1 >= tamanho){//Verifica se o barco cabe na linha introduzido pelo utilizador e se caber entra nesse loop
            for (int i = 0; i < tamanho_barco; i++) {
                if (coluna - i < 0 || tab[linha][coluna - i] != "A") {
                    posicaoValida = false;
                    break;
                }
            }

            if (posicaoValida) {
                for (int i = 0; i < tamanho_barco; i++) {
                    tab[linha][coluna - i] = tipo_do_barco;
                }
            }
        }

        // Verificação de posição e preenchimento na vertical (inversa)
        else if ((direcao == 'v' || direcao == 'V') && linha + tamanho_barco - 1 >= tamanho) {
            for (int i = 0; i < tamanho_barco; i++) {
                if (linha - i < 0 || tab[linha - i][coluna] != "A") {
                    posicaoValida = false;
                    break;
                }
            }

            if (posicaoValida) {
                for (int i = 0; i < tamanho_barco; i++) {
                    tab[linha - i][coluna] = tipo_do_barco;
                }
            }
        } else {
            posicaoValida = false;
        }
    }

    if (!posicaoValida){
        cout << "Posição ou direção inválida! Tenta outra vez!!!." << endl;
        cout << "Posição inválida! Tenta outra vez!!!." << endl;
        cout << "Informe a linha do seu preenchimento (entre 0 e 9): ";
        cin >> linha;

        cout << "Informe a coluna do seu preenchimento (entre 0 e 9): ";
        cin >> coluna;

        cout << "Deseja na posição horizontal(h) ou vertical(v): ";
        cin >> direcao;

        preenchimento(tab, tamanho_barco, linha, coluna, direcao,tipo_do_barco);//Volta perguntar isso sempre que for a posição invalida

    }

}

void mostrarTabelaAtualizado(string tab[tamanho][tamanho]) {
    cout << "      0       1      2       3       4      5      6      7      8     9  " << endl;
    for(int i = 0; i < tamanho; i++){
        cout << i << "  ";
        for(int c = 0; c < tamanho; c++){
            cout << "[ ";
            if (tab[i][c] == "B1") {
                cout << "B1 ";
            }else if (tab[i][c] == "B2") {
                cout << "B2 ";
            }else if (tab[i][c] == "B3") {
                cout << "B3 ";
            }else if (tab[i][c] == "B4") {
                cout << "B4 ";
            }else if (tab[i][c] == "B5") {
                cout << "B5 ";
            }else if(tab[i][c] != "B5" && tab[i][c] != "B4" && tab[i][c] != "B3" && tab[i][c] != "B2" && tab[i][c] != "B1"){
                cout<<" A ";
        }
            cout << "] ";

        }
        cout << "\n\n";
    }
}


bool Tiro(string tab[tamanho][tamanho], int linha, int coluna) {
    if (tab[linha][coluna] != "A" && tab[linha][coluna] != "X" && tab[linha][coluna] != " ") {
        // Aparece uma mensagem quando acerta um barco
        if (tab[linha][coluna] == "B1" || tab[linha][coluna] == "B2" || tab[linha][coluna] == "B3" || tab[linha][coluna] == "B4" || tab[linha][coluna] == "B5") {
            cout << "ACERTASTE no BARCO " << tab[linha][coluna] << " do adversario !!!!" << endl;
            sleep(3);

            // Verifica se o barco foi afundado
            if (BarcoAfundado(tab, tab[linha][coluna])) {
                cout << "AFUNDASTE o BARCO " << tab[linha][coluna] << " do adversario !!!!" << endl;
                sleep(3);
            }
        }

        tab[linha][coluna] = "X"; // Se acertar um barco vai aparecer X
        return true;
    } else {
        // Mostra uma mensagem quando erra
        sleep(1);
        cout << "ERRASTE!!!!" << endl;
        sleep(3);
        tab[linha][coluna] = " ";
        return false;
    }
}




void TabelaAtualizaComTiros(string tab[tamanho][tamanho]) {

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
                if(tab[i][j]==" A "){
                    cout<<"[  "<< tab[i][j] << "  ] ";
                }else{
            cout<<"[ "<< tab[i][j] << " ] ";
        }
        }
        cout <<"\n";
    }
}

bool BarcoAfundado(string tab[tamanho][tamanho], string tipoBarco) {
    // Verifica se todas as posições do barco estão marcadas como atingidas (X)
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            if (tab[i][j] == tipoBarco) {
                return false; // Ainda há uma parte do barco não atingida
            }
        }
    }

    return true; // Todas as partes do barco foram atingidas, o barco está afundado
}
