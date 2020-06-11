/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q5;

/**
 *
 * @author fernando.silva
 */
public class Q5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println(triangulo(0)); //0
        System.out.println(triangulo(1)); //1
        System.out.println(triangulo(2)); //3
        System.out.println(triangulo(3)); //6
        System.out.println(triangulo(4)); //10
    }
    
    public static int triangulo(int valor) {
        // Retorna 0 se vazio
        if (valor == 0) {
            return 0;
        }

        // retorna o valor somado a o próximo valor - 1
        // (Como se a contagem fosse de baixo pra cima)
        return valor + triangulo(valor - 1);
    }
    
}
