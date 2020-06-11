package q3;
/**
 *
 * @author fernando.silva
 */
public class Q3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println(orelhasCoelho(0));
        System.out.println(orelhasCoelho(1));
        System.out.println(orelhasCoelho(2));
        System.out.println(orelhasCoelho(3));
        System.out.println(orelhasCoelho(4));
    }
    
    //essa função apenas inclue a variável qtd e chama a ContaOrelha
    public static int orelhasCoelho (int num) {
        int qtd = 0;
        return ContaOrelha(num, qtd);
    }
    
    //Aqui é onde acontece a contagem
    public static int ContaOrelha (int num, int rest) {
        //Se houver ao menos uma orelha, reduz em 1 a qtd de coelho
        //e chama a ContaOrelha novamente pra contar os coelhos restantes.
        //O retorno de rest basicamente soma todas as orelhas contadas
        //do final pro início da árvor + o coelho atual
        if (num >= 1)
        {
            num--;
            return rest += ContaOrelha(num, rest) + 2;
        }
        else return 0;//retorna 0 quando acabarem os coelhos
    }
}
