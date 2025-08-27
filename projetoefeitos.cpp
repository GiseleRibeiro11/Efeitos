#include <iostream>

 #include <string>

 #include <vector>

 #include <cstdlib>

 #include <chrono>

 #include <thread>

 #include <clocale>





 using namespace std;

 using std::this_thread::sleep_for;

 using std::chrono::milliseconds;

 

 





 void exibe_menu_principal() {

     string sep(50, '*');

         cout << "   ****************************************************\n";

         cout << "   *                    EFEITO                        *\n";

         cout << "   *                                                  *\n";

         cout << "   * 1 - Diagonal Esquerda                            *\n";

         cout << "   * 2 - Diagonal Esquerda, Texto Invertido           *\n";

         cout << "   * 3 - Diagonais Cruzadas                           *\n";

         cout << "   * 4 - Diagonal Direita, Palavras Ordem Inversa     *\n";

         cout << "   * 5 - Em V                                         *\n";

         cout << "   * 6 - Deslizante                                   *\n";

         cout << "   * T - Todos                                        *\n";

         cout << "   * E - Encerrar                                     *\n";

         cout << "   *                                                  *\n";

         cout << "   *                                                  *\n";

         cout << "   ****************************************************\n";



 }

 void clear_screen() {

    #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)

        system("clear");

    #elif _WIN32

        system("cls");

    #endif

 }

 void pause() {

    cout << "Pressione ENTER para continuar...\n\n";

    string linha;

    getline(cin, linha);

}

// Efeito 1 - Diagonal Esquerda

void exibe_efeito1(string txt) {

    clear_screen();

    cout << "Efeito 1 - Diagonal Esquerda\n\n";

    int espacos = 0;

    for (auto& ch : txt) {

        cout << string(espacos, ' ') << ch << endl;

        espacos++;

    }

}





void exibe_efeito2(string txt) {

    clear_screen();

     cout << "Efeito 2 - Diagonal Esquerda, Texto Invertido\n\n";

     

     // Primeiro exibe MOURINHO

     string mourinho = "OHNIRUOM ESOJ ";

     int espacos = 0;

     for (char ch : mourinho) {

         cout << string(espacos, ' ') << ch << endl;

         espacos++;

     }

     

    

 }

 void exibe_efeito3(string txt) {

    clear_screen();

    cout << "Efeito 3 - Diagonais Cruzadas...\n\n";

     int tamanho = txt.length();

     vector<vector<char>> matriz(tamanho, vector<char>(tamanho, ' '));



     // Preenche as diagonais

     for (int i = 0; i < tamanho; i++) {

         // Diagonal principal (esquerda para direita)

         matriz[i][i] = txt[i];

         // Diagonal secundária (direita para esquerda)

         matriz[i][tamanho - 1 - i] = txt[i];

     }



     // Exibe a matriz

     for (int i = 0; i < tamanho; i++) {

         // Adiciona espaços para alinhar

         cout << "     ";

        

         for (int j = 0; j < tamanho; j++) {

             if (matriz[i][j] != ' ') {

                 cout << matriz[i][j];

             } else {

                 cout << " ";

             }

         }

         cout << endl;

     }

 }

 void exibe_efeito4(string txt)  {

    clear_screen();

     cout << "Efeito  4 - Diagonal  Direita, Palavras por Ordem inversa\n\n";

     

     // Primeiro exibe MOURINHO

     string mourinho = "MOURINHO JOSE ";

     int espacos = mourinho.length();

     for (char ch : mourinho) {

         cout << string(espacos, ' ') << ch << endl;

         espacos--;

     }

    

    

 }

void exibe_efeito5(string txt) {

    string texto = "ALBERTO";

    int n = texto.size();



    for (int i = 0; i < n; i++) {

        // Espaços antes da letra esquerda

        for (int j = 0; j < i; j++) cout << " ";



        cout << texto[i]; // Letra esquerda



        // Espaços entre as duas letras

        for (int j = 0; j < 2 * (n - 1 - i); j++) cout << " ";



        cout << texto[n - 1 - i] << endl; // Letra direita (invertida)

    }

}

void exibe_efeito6(string txt) {

    clear_screen();

    cout << "Efeito 6  - Texto Deslizante em Ciclo ao Longo da linha (ALBERTO)\n\n";

    string texto = "ALBERTO";

    string linha(40, ' ');

    int tamanho = texto.length();

    int posicao = 0;  // Adicionada a declaração da variável posicao

    cout << "\n  Para sair digite control + C!\n\n  ";

    

    while (true) {

        clear_screen();

        cout << "Efeito 6  - Texto Deslizante em Ciclo ao Longo da linha (ALBERTO)\n";

        cout << "\n  Para sair digite control + C!\n\n  ";

        linha = string(40, ' '); // Limpa a linha

        

        for (int i = 0; i < tamanho; i++) {

            int pos = (i + posicao) % 40;

            linha[pos] = texto[i];

        }

        

        cout << linha << endl;

        posicao = (posicao + 1) % 40;

        sleep_for(milliseconds(400));

        cout << "\n                                     ";

        

    }

    

}



void exibe_todos_efeitos(string txt) {

     

    cout << "\n=========================== EFEITO 1 ===========================\n\n";

    exibe_efeito1(txt);

    sleep_for(milliseconds(2000));



    cout << "\n========================== EFEITO 2 ============================\n\n";

    exibe_efeito2(txt);

    sleep_for(milliseconds(2000));

     

    cout << "\n=========================== EFEITO 3 ===========================\n\n";

    exibe_efeito3(txt);

    sleep_for(milliseconds(2000));



    cout << "\n=========================== EFEITO 4 ============================\n\n";

    exibe_efeito4(txt);

    sleep_for(milliseconds(2000));



    cout << "\n========================== EFEITO 5  ============================\n\n";

    exibe_efeito5(txt);

    sleep_for(milliseconds(2000));

     

    cout << "\n========================== EFEITO 6 =============================\n\n";

    exibe_efeito6(txt);

    sleep_for(milliseconds(2000));



    cout << "\n=================================================================\n";

}



 int main() {

    setlocale(LC_ALL, "pt_PT.UTF-8");

     string texto = "JOSE MOURINHO";

     

     bool continuar = true;

     while (continuar){



        clear_screen();



          exibe_menu_principal();

          cout << "\n                    " << endl;

          cout << "                Digite a sua opção!";

          string opcao;

          cin >> opcao;



          if(opcao == "1"){



             exibe_efeito1(texto);

          }

          else if(opcao == "2"){

             exibe_efeito2 (texto);

          }

          else if (opcao == "3") {

          exibe_efeito3 (texto);

          }

          else if (opcao == "4") {

          exibe_efeito4 (texto);

          }

          else if (opcao == "5") {

          exibe_efeito5 (texto);

          }

          else if (opcao == "6"){

          exibe_efeito6 (texto);

          }

          else if (opcao == "T" || opcao == "t") {

          clear_screen();

          exibe_todos_efeitos(texto);

          }

          else if (opcao == "E" || opcao == "e") {

             cout << "Encerrando o programa..." << endl;

             break;

          }

          else {

             cout <<"\n                                          " << endl;

             cout <<"        ************************************" << endl;

             cout <<"        *        OPÇÃO INVÁLIDA!           *" << endl;

             cout <<"        *   Por favor, escolha uma opção   *" << endl;

             cout <<"        *   Válida do menu (1-6, T ou E).  *" << endl;

             cout <<"        ************************************" << endl;

             

         }

           if (opcao != "E" && opcao != "e") {

             cout << "\nPressione Enter para continuar...";

             cin.ignore();

             cin.get();

         }

     }

     return 0;

 }
