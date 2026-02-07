extends RefCounted

var vec: Vector4i = Vector4i()

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

func getZ() -> int:
	return vec.x

func setZ(value: int) -> int:
	vec.z = value
	return vec.z

func getW() -> int:
	return vec.w

func setW(value: int) -> int:
	vec.w = value
	return vec.w

func abs() -> Vector4i:
	return vec.abs()

func clamp(pMin: Vector4i, pMax: Vector4i) -> Vector4i:
	return vec.clamp(pMin, pMax)

func clampi(pMin: int, pMax: int) -> Vector4i:
	return vec.clampi(pMin, pMax)

func distanceDquaredTo(to: Vector4i) -> float:
	return vec.distance_squared_to(to)

func distanceTo(to: Vector4i) -> float:
	return vec.distance_to(to)

func length() -> float:
	return vec.length()

func lengthSquared() -> float:
	return vec.length_squared()

func max(with: Vector4i) -> Vector4i:
	return vec.max(with)

func maxAxisIndex() -> int:
	return vec.max_axis_index()

func maxi(with: int) -> Vector4i:
	return vec.maxi(with)

func min(with: Vector4i) -> Vector4i:
	return vec.min(with)

func minAxisIndex() -> int:
	return vec.min_axis_index()

func mini(with: int) -> Vector4i:
	return vec.mini(with)


func sign() -> Vector4i:
	return vec.sign()

func snapped(step: Vector4i) -> Vector4i:
	return vec.snapped(step)

func snappedi(step: int) -> Vector4i:
	return vec.snappedi(step)

func multiply(right) -> Vector4i:
	return vec * right

func add(right) -> Vector4i:
	return vec + right

func subtract(right) -> Vector4i:
	return vec - right

func divide(right) -> Vector4i:
	return vec / right

func lessThan(right: Vector4i) -> bool:
	return vec < right

func lessThanOrEqualTo(right: Vector4i) -> bool:
	return vec <= right

func greaterThan(right: Vector4i) -> bool:
	return vec > right

func greaterThanOrEqualTo(right: Vector4i) -> bool:
	return vec >= right

func isEqualTo(right: Vector4i) -> bool:
	return vec == right
