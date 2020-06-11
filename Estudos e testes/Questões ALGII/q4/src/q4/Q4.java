package q4;
/**
 *
 * @author fernando.silva
 */
public class Q4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println(contarX("xxhixx")); //4
        System.out.println(contarX("xhixhix")); //3
        System.out.println(contarX("hi")); //0
    }
    
    public static int contarX(String texto) {
        // Retorna 0 se vazio
        if (texto.isEmpty()) {
            return 0;
        }

        // retorna o primeiro valor da string
        char primeiro = texto.charAt(0);
    
        // se for igual a x, o valor é igual a 1, senão é zero
        int valor = (primeiro == 'x') ? 1 : 0; 

        // retorna o valor + a contagem do restante da string
        return valor + contarX(texto.substring(1));
    }
}
