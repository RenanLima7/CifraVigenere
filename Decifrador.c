#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000

// Função para calcular a pontuação de um texto decifrado com base na frequência de letras em português
int calcularPontuacao(char texto[]) {
    int pontuacao = 0;
    int frequencia[26] = {0}; // Array para contar a frequência de cada letra
    char letras_comuns[] = {'a', 'e', 'o', 's', 'r', 'i', 'n', 'd', 'm'};

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            int indice = tolower(texto[i]) - 'a';
            frequencia[indice]++;
        }
    }

    // Atribuir pontuações com base na frequência de letras comuns em português
    for (int i = 0; i < sizeof(letras_comuns) / sizeof(letras_comuns[0]); i++) {
        int indice = letras_comuns[i] - 'a';
        pontuacao += frequencia[indice];
    }

    return pontuacao;
}

// Função para decifrar o texto usando a cifra de Vigenère com força bruta
void decifrarForcaBruta(char texto[], int texto_len) {
    char texto_decifrado[MAX_SIZE];
    char chave[MAX_SIZE];
    char melhor_decifrado[MAX_SIZE];
    int melhor_pontuacao = 0;

    for (int k = 1; k <= 4; k++) { // Supondo que a chave tenha no máximo 4 caracteres
        for (int i = 0; i < k; i++) {
            chave[i] = 'A'; // Começando com todas as letras 'A'
        }
        chave[k] = '\0';
        
        do {
            int chave_len = strlen(chave);
            for (int i = 0, j = 0; i < texto_len; i++) {
                char letra = texto[i];
                if (isalpha(letra)) {
                    char base = isupper(letra) ? 'A' : 'a';
                    texto_decifrado[i] = ((toupper(letra) - toupper(chave[j]) + 26) % 26) + base;
                    j = (j + 1) % chave_len;
                } else {
                    texto_decifrado[i] = letra;
                }
            }
            texto_decifrado[texto_len] = '\0';

            // Calcular a pontuação do texto decifrado
            int pontuacao = calcularPontuacao(texto_decifrado);

            // Se a pontuação for maior que a melhor pontuação até agora, atualizar o melhor resultado
            if (pontuacao > melhor_pontuacao) {
                melhor_pontuacao = pontuacao;
                strcpy(melhor_decifrado, texto_decifrado);
            }

            // Atualizar a chave para a próxima combinação
            int i = k - 1;
            while (i >= 0 && chave[i] == 'Z') {
                chave[i] = 'A';
                i--;
            }
            if (i < 0) // Todas as combinações foram tentadas
                break;
            chave[i]++;
        } while (1);
    }

    // Imprimir o melhor resultado encontrado
    printf("Texto decifrado mais provável:\n%s\n", melhor_decifrado);
}

int main() {
    
    char texto[MAX_SIZE] = "Ixbpsrmrho a Qynps hae Zmasirs Hmejmv i uye hae ibpqvmezgmae qeie irruuyeoihodew qgi topiqoe xir ze zipe. Gape zimkim q yqa vsvnmhe uzmga, ditlqxe dq hisosfedxes, mzinfyvae i qoyirtaw mnqwuuqgmvqmw. Dqwhe qbtlaver mw qadezixles zexudems mxi mqvkuxler zew cgpxudew e fvedugsee pscmmw, o yyrda iwtm gleus he xykadiw fmwgizertqw isbivazhs pmve sqvim qbtlavedaw. Ymm hes rsvmmw qauw imagmozertqw he hmejmv i eyferoev ey yqa vsvnmhe pqpe nmxyrqde. Dq gemurlapew pqpes fvmltew ejyfedertqw hae jpodiwtmw xratmcmmw afi isoepapew aaw tiosw dmw qaviwtawes ysrtmrlae, e rafyvele sfqvicq yqa heviqhedq mrfurmtm hi pmmwasirs piwlgqfrmrxee term wirqq epdigimhes. A wsm pew cmgloqmvae, s ghqmvo pew fxsvee wmlhiwtdiw e m wineegaa hs vqrxo osrtde s rawxo ees abirae epggrw daw trmdirqw uuq ekumvhay sw vuenazxis qq fuege dq ezezxyrmw eo mv pihvi. Axiq dmw qadezixles zexudems, mw zimkine xemniq naw tedqmtqq qedkyltev nmw guxxyrmw i tdehiosis grmcmw he pmjedirtqw tadxis ps quzhs. Dq ibpxsvad sw tqqtlaw enfmkoe hs sghisfi esuexios etq terfmgibev dq jisfmzauw goxsvipsw nm Eqedmga Xexize, gape heexmna sjedige gqe obsvtgrmdmhi uzmga pi epdirdqv i cdiwcqv goys teewsa. Qbtedmqezxer zszoe webavis pe guxmradme lagel, percmv eo esq dm qysuge tdehiomsnmp i carzedwer osq oe lebuxenfiw lageie weo mtinmw elsyqae hes yereuves bipae uyauw topiqoe rss osreoxer osq ae gsmgrmdmhis cyi vuwmtmqss. Zs inferta, zmavev tmqfey tsdq wir gqe javrape mnfiviav. Pozki dm vsture da hma-m-hma, fiqoe e ghmrge pi verpituv wonvi nawwae zmdmw, roewss hepodiw e zswsaw sbvixihsw. Mgmxae zizqw, i dgvenfi ymm zmasiq qgi inosrtdeqoe e mnetmrmgeo beva yyhazges emknujmcmxmvmw im zswsmw zipew, sqne mghenps he oevrqmva, osqeoerda yq nazs rqpecusrayirta sy suqtlqwqezxi apsxazhs uye tedwteoxmvm qeie tssuxmvm iq rqpecms eo yyrda. Qisys uumrho hsptmqss beva oewa, mw peyfvazges pi roewes hmegqrw carxizyem m rss urwpuver. Mw jofsw qgi xideqoe, sw aymkoe uye rmdeysw e mw liexsruew qgi zihiqoe wi tavray xisayvoe tveomssaw uuq kyadhemaw tade weytve qq roewss osvaosis. Q, e qepmha cyi pxereveqoe rssee trabmmm ezezxyrm, wsmaw peyfvapsw dq uye a qynps i vmwxo q gleus he bswsufmluhedqw, isbivazhs pmve sqvim qbtlavedmw. Todxenfs, raa mqpavxa ei isfeqoe zmaverda term s sufvs lmhs da qynps su mtinmw ixbpsrmrho zswsm tvobvma omhapi, gape zimkim q yqa atsrfyripehe pi grqwgiyirta, hisosfedxe e osrejes. Ezxeo, heqoe tigmv roewes ysghupes, mfvid rssesw cavecaiw pmve o piwcarleomho q iqbmvgad re pdsbiye krmrhe mzinfyva cyi a hmha fiq a ajirqgir. A qynps isfe isbivazhs - vmqss qbtlave-la nynfsw! Ejtpoderda s Quzhs dmw Zimkine Zmavev e gqe dmw ixbiviqrgimw qauw indmuuqgidaves cyi pahimaw xed re vuhe. Cmhe vuekey i ymm nsrzeha grmcm, vipxixa pi heegsbqvxae, ezezxyrmw i maqinfsw iziwqgigihims. Piwdq ibpxsvad ew mmvevuplae retgveie exe yivggplad res oyptgves q xvapmgoqw pooems, a qynps isfe ghqms dq pygmvis rewcurenfiw eetirmrho beva eivey ibpxsvapsw. Uye hae jsryew mmmw eysgiarenfiw dq zmavev e qqfadger qq ymm nsrzeha bipa zexudida. Pi gaymrhmhes bipae xvixles qbybqvenfiw dmw jlavisfew tdstioems mxi eegelmhes msw pugss pew mmnisfswae qsnferhmw, e nmxyrqde oriveoi ymm zeruihapi mnrmrife he bemsmkine hisxyqbdertqw tade wediq abvicuehae. S woy hes oeghaimrmw, s ctimra hes rpsrqw wixzisfvis q e wezwecms ho hirta gsnfve o dswta weo mtinmw elsyrs psw pdedediw qgi eggevdmq ss hmejmrxee iq bgwga pi evqrxudew aa ev luzve. Mpim pew mmvevuplae retgveie, ew vuekezw xayfim zsw pqvqifiq mqvkuxler zew cgpxudew e fvedugsee yrioew dq hmfqvinfiw pmvxee hs mgrho. Pi ixbpsrmv ss fiqpxsw azxmgaw ho eyheexi aemetugs afi tadxmcuter pi jeexmvmmw capsruhss ze Emqvmcm Peture, cmhe dqwxizs sfqvicq yqa atsrfyripehe grmcm hi abvinpiv e ovisoiv caqs pqwwom. Ibpqvmmqrxad rsvaw wansvee he cgpmnmvma xsgax, henoev aa wsm pe quemga fvedugmozep e osrvqvwad gsm aw lanmxazxis xsgauw waa etezew axkymmw hae qenqmvae tilmw uummw pahimaw roe gsnqgxad gsm mw goyyripehee uye hmwifeqoe. Rs ezxenfs, zimner feqbqq topi wed yqa vsvnmhe izxirusv. Larke pe vofmra ps him-e-him, ximaw e ctercq hi rqjpefmv safve zswsmw zipew, nawwoe zelavis q rssesw onnituzss. Yymtmw zeliw, e pyvazxi uye zimkim cyi ezgsnfvemaw e izwtidegaa term qydmrgae wmgzmjioexihew ey rsseew vuhes, eina yyhazhs dq gerdimrm, gsmqgenps ym zszo dipaomsnmqinfs su emqpxiwmqrxe mhstmrho gqe pqvwpqgxihe qauw toemxihe im dipaoes aa qynps. Qeeqs qgerda zslfeqoe term gesm, ew lqqfrmrgae hi nawwae zmasirs osrturyay e roe mrsbmvad. Ew faxss cyi tuvemaw, ss mqmgaw uuq jmzqqss q ew huwxodmes cyi vuzimaw we fsvnmq xeesyraw trqgmoesw qgi kumvhaysw pmve sqqtrq iq nawwoe gsrmgsee. I, e mqhmdm uye bpenqnemaw roewe pdsbiye evqrxude, woysw lqqfrmhss pi uuq s quzhs e hewta i ghqms dq tssemfixmhapiw, eetirmrho beva eivey ibpxsvapew. Pavxazxs, nms mmbsvtm wi eexemaw zimnenps tade s ogxvo xeho ps quzhs og etezew ejtpoderda rssee tratvim gmdmhi, cmhe vuekey i ymm stodxynuhedq hi cdiwcuqinfs, heegsbqvxa q gsnqbeo. Qrxaa, zemaw tesev nawwae qsctmpae, efruv roewss osvaosis beva a hisosrhqgmda i imnevcmv ra bvsxuqe gderdq ezezxyrm uye m zmdm xim m sjediged. S quzhs eexe eetirmrho - heqoe ibpxsva-xs nuzxss! Qbtlavenps s Mgrho pew Vuekezw Zimner q yqa pew ejtiruircuew mmmw ezvmqgigepsvae uye bsheysw tqv ra hmha. Oeha hmegqq i uye nodredm yrioe, vebpitm hi dqwgonivtmw, evqrxudew e ysqezxss uriscyicuziie. Hispi ixbpsrmv es yevahmphmw rafyvauw etq qirsyphmv rae gylfyvae i xrmhmcaiw lageie, s quzhs eexe ctimo pi pusevee jesomrazxis qwtederda term wirqq ixbpsrmhss. Gqe dmw jodqes yems qqscusrazxis pi zimner q iqbmvgad iq uye nodredm tilm retgvizm. Hi cmqmntehae tilmw xruplae ibunivazxis pew fxsveexes fvspugeie exe qwgaxehae ess bmgoe hes yeneexssmw qozxentew, a zexudida ajirqgi uye zadmidmhi izjmnuxe dq teieekezw heepymnvenfiw pmve sqvim mtveomedmw. S saq hae gectsiidew, o oliids hae jpodiw supzeexvee i e sqrwaoes da zinfs gozxva a vssfs waa etezew axkyne hss bvezqvis cyi asyerpeq oe zmavertqw im nywcm hi ahirtgves ms er xmzrq. Epey hes yevahmphmw rafyvauw, es hmegqrw tmqfey rss bivmuxim yivggplad res oyptgves q xvapmgoqw ynuges pi hirivezxis bevtqw ho yyrda. Hi ejtpodev oe ximbpss mrxissw da wydqwxe mwmafmgo mxi pmvxiomtad hi fqwxihems ospodmhoe re Ayivioe Pafmra, oeha piwturs oriveoi ymm stodxynuhedq yrioe he mtvezhir q gveegir osqo biwsae. Ixbiviyirtmv rohsw smfsrqw ha oypizevim pscmp, hazger ms woy he mgwmcm xvapmgiarel q gsnhivsmv goy sw hmfmtmrxee pscmmw sms epqres mpkuyew dmw qazimrmw texew qgems bsheysw naw gozigtmv goy ew caqynuhedqw uuq zmsuxemaw.";
    int texto_len = strlen(texto);

    decifrarForcaBruta(texto, texto_len);

    return 0;
}

