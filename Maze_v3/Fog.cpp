#include "Fog.h"
Fog::Fog(int viewRadius, char fogSymbol) : Entity(Vector2Int(), fogSymbol) {
	_ViewRadius = viewRadius;
}
void Fog::Draw(Field* field) {
	auto renderSize = field->mainCamera->renderSize;
	auto renderCenter = Vector2Int(renderSize.X/2, -renderSize.Y/2);
	int sqrtRadius = _ViewRadius * _ViewRadius;
	for (int x = 0; x < renderSize.X; x++)
	{
		for (int y = 0; y > -renderSize.Y; y--)
		{
			int x1 = x - renderCenter.X;
			int y1 = y - renderCenter.Y;
			int leftPartOfCircleFormula = x1 * x1 + y1 * y1;
			if(leftPartOfCircleFormula > sqrtRadius)
				field->ChangePoint(p_SymbolToDraw,Vector2Int(x, y));
		}
	}
}