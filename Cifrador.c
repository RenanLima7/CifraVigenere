#include <stdio.h>
#include <string.h>
#include <ctype.h>

char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

char cifrar_caractere(char letra, char key) {
    int kj = tolower(key) - 'a'; 
    int posicao;
    
    if(isalpha(letra)){
        if(isupper(letra)){
            posicao = letra - 'A'; 
            return toupper(alfabeto[(posicao + kj) % 26]); 
        } else {
            posicao = letra - 'a'; 
            return alfabeto[(posicao + kj) % 26]; 
        }
    }
    return letra; 
}

char* cifra(char textoClaro[], char key[]) {
    int cont = 0;
    static char textoCifrado[10000]; 

    for (int i = 0; i < strlen(textoClaro); i++) {
        char letra = textoClaro[i];
        textoCifrado[i] = cifrar_caractere(letra, key[cont]);
        
        if(isalpha(letra)) {
            cont = (cont + 1) % strlen(key); 
        }
    }

    textoCifrado[strlen(textoClaro)] = '\0';
    return textoCifrado;
}

int main() {
    system("cls");
    
    char textoClaro[] = "Minha mae entrou em extase quando pegamos a carta no correio. Ela ja tinha decidido que todos os nossos problemas estavam solucionados, tinham desaparecido para sempre. O grande empecilho em seu plano brilhante era eu. Eu nao me considerava uma filha muito desobediente, mas tambem nao era uma santa. Nao queria ser da realeza. Nao queria ser Um. Nao queria nem tentar. Escondi-me no meu quarto, o unico lugar onde podia fugir do falatorio da casa cheia. Procurava um argumento que dobrasse minha mae, mas, ate entao, tudo o que tinha era uma coletanea de opinioes sinceras? Nao me parecia que ela fosse dar ouvidos a nenhuma delas. Eu nao conseguiria escapar da minha mae por muito tempo. Era quase hora do jantar, e eu, a filha mais velha que ainda morava em casa, tinha que ajudar na cozinha. Pulei da cama e caminhei para o ninho de cobras. Minha mae me recebeu com um olhar furioso, mas nao disse nada. Nos duas nos moviamos pela cozinha e pela sala de jantar sem falar como em uma danca silenciosa  enquanto preparavamos frango, macarrao e torta de maca, e punhamos a mesa para cinco pessoas. Bastava eu desviar os olhos do que estava fazendo para ela me corrigir com um olhar severo, como se assim fosse me deixar constrangida o bastante para querer as mesmas coisas que ela. Minha mae usava essa tatica as vezes. Quando eu queria mudar de emprego porque achava que a familia que nos hospedava era grosseira sem necessidade. Ou quando ela queria que eu fizesse uma faxina pesada porque nao tinhamos dinheiro para pagar alguem do Seis para nos ajudar. Algumas vezes dava certo. Outras, nao. E esse era um ponto em que ninguem podia me dobrar. Minha mae nao tinha o que fazer quando eu teimava. Puxei a ela, de modo que nao podia ficar surpresa. Mas o problema nao era so comigo. Ela andava tensa. O verao chegava ao fim e logo viriam os meses frios. E as preocupacoes. Minha mae botou a jarra de cha na mesa com raiva. Fiquei com a boca cheia d?agua so de imaginar o cha gelado com limao. Mas eu tinha que esperar; seria um desperdicio tomar meu copo agora e depois ter que beber agua no jantar Mas voce vai morrer se preencher o formulario?   ela disse, sem se aguentar.  A Selecao pode ser uma oportunidade maravilhosa para voce, para todos nos. Suspirei alto, pensando que preencher aquele formulario seria como a morte para mim. Nao era segredo que os rebeldes   as colonias subterraneas que odiavam Illea, nosso vasto e relativamente jovem pais   investiam em ataques cada vez mais frequentes e violentos ao palacio. Ja tinhamos visto os rebeldes em acao em Carolina. A casa de um dos magistrados fora completamente incendiada, e os carros de pessoas da Dois foram destruidos. Houve ate uma espetacular fuga da prisao: eles libertaram uma adolescente que engravidara e um Sete que era pai de nove filhos, de modo que ate eu achei que eles estavam certos daquela vez. Mas, alem das ameacas, eu sentia que so pensar na Selecao ja fazia meu coracao doer. Nao consegui esconder meu sorriso enquanto pensava em todas as razoes para permanecer exatamente onde estava.   Os ultimos anos tem sido muito dificeis para seu pai   minha mae estrilou.   Se voce tiver um pouco de compaixao, vai pensar nele. Meu pai. Sim. Eu queria ajuda-lo. E May e Gerad. E ate minha mae. Eu nao tinha como sorrir diante da maneira como ela expos a situacao. Fazia tempo demais que as coisas nao iam bem. Eu me perguntava se meu pai veria a Selecao como um meio de fazer com que tudo voltasse ao normal, se e que o dinheiro podia melhorar as coisas. Nao que nossa situacao fosse tao precaria a ponto de temermos por nossa sobrevivencia ou algo assim. Nao eramos miseraveis. Mas acho que nao estavamos muito longe disso. Nossa casta era a terceira antes do fundo do poco. Eramos artistas. E os artistas e musicos classicos estavam so tres degraus acima da sujeira. Literalmente. Nosso dinheiro era curto, viviamos na corda bamba e nossa renda dependia muito da mudanca de estacoes. Lembro-me de ter visto num livro de historia bem gasto que todas as datas especiais costumavam ser comemoradas nos meses de inverno. Halloween, Acao de Gracas, Natal e Ano-Novo. Um depois do outro. O Natal ainda era no mesmo dia. Nao da para mudar o aniversario de uma divindade. Mas quando Illea firmou o grande acordo de paz com a China, o Ano-Novo passou para janeiro ou fevereiro, dependendo da lua. Todas as comemoracoes de Acao de Gracas e do dia da independencia da nossa metade do mundo foram reunidas na Festa da Gratidao, realizada no verao. Era tempo de celebrar a formacao de Illea, de nos alegrar por ainda existirmos. Eu nao sabia o que era Halloween. Simplesmente desapareceu. Assim, pelo menos tres vezes ao ano a familia inteira tinha emprego em tempo integral. Meu pai e May faziam pecas de artesanato que os clientes compravam para dar de presente. Minha mae e eu nos apresentavamos em festas   eu cantava e ela tocava piano  , e aceitavamos todo trabalho possivel. Quando eu era mais nova, tinha medo de me apresentar em publico, mas agora tratava de entrar no clima da musica de fundo. Assim eramos aos olhos de quem nos empregava: estavamos ali para ser ouvidos, nao vistos. Gerad ainda nao tinha descoberto seu talento, mas ele so tinha sete anos. Ainda lhe restava um tempinho. Em breve as folhas das arvores mudariam de cor e nosso mundinho ficaria balancado mais uma vez. Cinco bocas e apenas quatro trabalhadores. Sem emprego garantido ate o Natal. Quando eu via as coisas desse jeito, a Selecao parecia uma corda a qual eu podia me agarrar. Aquela carta idiota talvez me tirasse do fundo do poco, e entao eu poderia puxar minha familia comigo. Eu observava minha mae. Para uma Cinco, ela ate que estava bem robusta, o que era estranho. Nao era uma glutona, mas tambem nao havia fartura em casa. Talvez fosse assim que o corpo ficava depois de cinco filhos. Os cabelos dela eram ruivos, como os meus, mas cheios de fios brancos, que tinham aparecido de repente e aos montes uns dois anos antes. Umas ruguinhas sulcavam o canto dos olhos, embora ainda fosse bastante jovem, e eu podia reparar que ela circulava pela cozinha com as costas curvadas, como se carregasse um peso invisivel nos ombros.";
    char key[] = "LUVA";

    printf("\n\t\t\t================================================");
    printf("\n\t\t\t                 TEXTO CIFRADO             ");
    printf("\n\t\t\t================================================\n\n");

    printf("%s\n", cifra(textoClaro, key));

    printf("\n\n");

    system("pause");
    
    return 0;
}
