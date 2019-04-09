public class Num extends Token {
  public final int value;
  public final int intPart;
  public final int fracPart;

  public Num(int v) {
    super(Tag.NUM);
    value = v;
  }

  public Num(int v1, int v2) {
    super(Tag.NUM);
    intPart = v1;
    fracPart = v2;
  }
}