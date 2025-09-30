public class Rook extends Piece 
{
	public Rook()
	{
		this.SetText("Rook");
	}
	
	public Rook(GameManager game) 
	{
		super(game);
		this.SetText("Rook");
	}
	
	// 놓은 칸을 기준으로 놓을 수 없는 칸 계산
	@Override
	public void SetCannotPlaceCells(int x, int y) 
	{
		game.SetBooleanPlacedRook(x, y);
	}
}
