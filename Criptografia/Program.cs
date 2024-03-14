using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Criptografia
{
    public class Program
    {
        #region Keys By Nationality
        private static readonly string _portugues = "AESRINDUMCLTPVGQBFJXZKYW";
        private static readonly string _espanhol = "AEOSNRILUDCTMPYBVQGFHJXZKW";
        private static readonly string _alemao = "ENIRSATUHDCGMOBWFKZVPJYXQ";
        private static readonly string _frances = "ESAINRULTODCPMÉVQFBGHJXYZKW";
        private static readonly string _ingles = "ETAOINSHRDLUCMFYWGPBVKJXQZ";
        #endregion

        private readonly static string _cipherText =
        //"A lua cheia ilumina a noite escura, revelando segredos ocultos sob as sombras das árvores. O vento sussurra mistérios, enquanto as estrelas contam histórias antigas no céu infinito. A jornada da lua é um espetáculo mágico que encanta os corações dos observadores noturnos.";
        "V zgjv xpvm ivqarz v rgvmt qzvpm, jvzymvtre zmrxgmirt zmzmr jvt zmpmzivivt qzvm vmztr zr gvtgrmr. V xivmr jvffmvgt zrmzmgrq, zmvgzmr zrtzmtzsr qzvmr zmpmztv zmivivtq vrgtzrgzmt. V jvtzmziv zmz gz zmrxgmirt vtrgvivlz zm xztrvm vmzvmvgt. V mzrztgzv rgvmt vzvt z vtrgzr ivgqzvmgr zm gvmqtrzr zmvmzmvtvgt zmrgtrzvmr zmzrgztrzmr xzvmivzgt zm gvtivgtq zmvgzmrzivgt zmzmrzmzvm.";

        public static void Main(string[] args)
        {
            string cipherText = _cipherText.ToLower();

            Console.WriteLine("Escolha a key que deseja utilizar:\n" +
                "\n0 = Português" +
                "\n1 = Espanhol" +
                "\n2 = Alemão" +
                "\n3 = Francês" +
                "\n4 = Inglês"
            );

            string option = Console.ReadLine();

            string key = GetKey(option);

            Dictionary<char, int> ocorrencias = GetOccurrences(cipherText);

            string plainText = Decrypt(cipherText, ocorrencias, key);

            Console.WriteLine("Key: " + key);

            Console.WriteLine("\n\nTexto Plano:\n\n" + plainText);

            Console.ReadLine();
        }

        public static Dictionary<char, int> GetOccurrences(string cipherText)
        {
            Dictionary<char, int> ocorrencias = new Dictionary<char, int>();
            cipherText = Regex.Replace(cipherText, @"[\p{M}\s\p{P}]|[^\w\s]", "");

            try
            {
                foreach (char caractere in cipherText)
                {
                    if (ocorrencias.ContainsKey(caractere))
                        ocorrencias[caractere]++;
                    else
                        ocorrencias.Add(caractere, 1);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("GetOccurrences - " + ex.Message + " - " + ex.InnerException);
            }

            return ocorrencias;
        }

        public static string GetKey(string option)
        {
            try
            {
                switch (option)
                {
                    case "0":
                        return _portugues;
                    case "1":
                        return _espanhol;
                    case "2":
                        return _alemao;
                    case "3":
                        return _frances;
                    case "4":
                        return _ingles;
                    default:
                        return _portugues;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("GetKey - " + ex.Message + " - " + ex.InnerException);
                return _portugues;
            }
        }

        public static string Decrypt(string cipherText, Dictionary<char, int> ocorrencias, string key)
        {
            StringBuilder textPlain = new StringBuilder();
            
            try
            {
                // Dicionário de substituições
                Dictionary<char, char> substituicoes = new Dictionary<char, char>();

                int index = 0;

                // Processar letras mais frequentes
                foreach (var ocorrencia in ocorrencias.OrderByDescending(pair => pair.Value))
                {
                    char letraCifrada = ocorrencia.Key;

                    if (!substituicoes.ContainsKey(letraCifrada) && Char.IsLetter(letraCifrada))
                    {
                        char letraSubstituida = key[index];
                        substituicoes.Add(letraCifrada, letraSubstituida);

                        index++;
                    }
                }

                // Substituir letras no texto cifrado
                foreach (char caractere in cipherText)
                {
                    textPlain.Append(substituicoes.ContainsKey(caractere) ? substituicoes[caractere] : caractere);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Decrypt - " + ex.Message + " - " + ex.InnerException);
            }

            return textPlain.ToString();
        }
    }
}
