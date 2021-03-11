public class NumFloat extends Token {
  public final int intPart;
  public final int fracPart;  


  public NumFloat(int v1, int v2) {
    super(Tag.NUM);
    intPart = v1;
    fracPart = v2;
  }
}