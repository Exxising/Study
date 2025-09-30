public class Bishop extends Piece 
{
	public Bishop() 
	{
		this.SetText("Bishop");
	}
	
	public Bishop(GameManager game) 
	{
		super(game);
		this.SetText("Bishop");
	}
	
	// 놓은 칸을 기준으로 놓을 수 없는 칸 계산
	@Override
	public void SetCannotPlaceCells(int x, int y) 
	{
		game.SetBooleanPlacedBishop(x, y);
	}
}
