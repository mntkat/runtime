extends RefCounted

var vec: Vector2i = Vector2i()

func getX() -> int:
	return vec.x

func setX(value: int) -> int:
	vec.x = value
	return vec.x

func getY() -> int:
	return vec.y

func setY(value: int) -> int:
	vec.y = value
	return vec.y

func abs() -> Vector2i:
	return vec.abs()


func aspect() -> float:
	return vec.aspect()

func clamp(pMin: Vector2i, pMax: Vector2i) -> Vector2i:
	return vec.clamp(pMin, pMax)

func clampi(pMin: int, pMax: int) -> Vector2i:
	return vec.clampi(pMin, pMax)

func distanceDquaredTo(to: Vector2i) -> float:
	return vec.distance_squared_to(to)

func distanceTo(to: Vector2i) -> float:
	return vec.distance_to(to)

func length() -> float:
	return vec.length()

func lengthSquared() -> int:
	return vec.length_squared()

func max(with: Vector2i) -> Vector2i:
	return vec.max(with)

func maxAxisIndex() -> int:
	return vec.max_axis_index()

func maxi(with: int) -> Vector2i:
	return vec.maxi(with)

func min(with: Vector2i) -> Vector2i:
	return vec.min(with)

func minAxisIndex() -> int:
	return vec.min_axis_index()

func mini(with: int) -> Vector2i:
	return vec.mini(with)

func sign() -> Vector2i:
	return vec.sign()

func snapped(step: Vector2i) -> Vector2i:
	return vec.snapped(step)

func snappedi(step: int) -> Vector2i:
	return vec.snappedi(step)

func multiply(right) -> Vector2i:
	return vec * right

func add(right) -> Vector2i:
	return vec + right

func subtract(right) -> Vector2i:
	return vec - right

func divide(right) -> Vector2i:
	return vec / right

func lessThan(right: Vector2i) -> bool:
	return vec < right

func lessThanOrEqualTo(right: Vector2i) -> bool:
	return vec <= right

func greaterThan(right: Vector2i) -> bool:
	return vec > right

func greaterThanOrEqualTo(right: Vector2i) -> bool:
	return vec >= right

func isEqualTo(right: Vector2i) -> bool:
	return vec == right
