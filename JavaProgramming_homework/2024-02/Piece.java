// 기본적인 말의 프레임
public abstract class Piece {
	String text;
	GameManager game;
	
	public Piece() {}
	
	public Piece(GameManager game) { this.game = game; }
	
	public String GetText() { return text; }
	
	public void SetText(String str) { text = str; }
	
	public abstract void SetCannotPlaceCells(int x, int y);
}
