extends RefCounted

var vec: Vector4 = Vector4()

func getX() -> float:
	return vec.x

func setX(value: float) -> float:
	vec.x = value
	return vec.x

func getY() -> float:
	return vec.y

func setY(value: float) -> float:
	vec.y = value
	return vec.y

func getZ() -> float:
	return vec.x

func setZ(value: float) -> float:
	vec.z = value
	return vec.z

func getW() -> float:
	return vec.w

func setW(value: float) -> float:
	vec.w = value
	return vec.w

func abs() -> Vector4:
	return vec.abs()


func ceil() -> Vector4:
	return vec.ceil()

func clamp(pMin: Vector4, pMax: Vector4) -> Vector4:
	return vec.clamp(pMin, pMax)

func clampf(pMin: float, pMax: float) -> Vector4:
	return vec.clampf(pMin, pMax)

func cubicInterpolate(b: Vector4, preA: Vector4, postB: Vector4, weight: float) -> Vector4:
	return vec.cubic_interpolate(b, preA, postB, weight)

func cubicInterpolateInTime(b: Vector4, preA: Vector4, postB: Vector4, weight: float, bT: float, preAT: float, postBT: float) -> Vector4:
	return vec.cubic_interpolate_in_time(b, preA, postB, weight, bT, preAT, postBT)

func directionTo(to: Vector4) -> Vector4:
	return vec.direction_to(to)

func distanceDquaredTo(to: Vector4) -> float:
	return vec.distance_squared_to(to)

func distanceTo(to: Vector4) -> float:
	return vec.distance_to(to)

func dot(with: Vector4) -> float:
	return vec.dot(with)

func floor() -> Vector4:
	return vec.floor()

func inverse() -> Vector4:
	return vec.inverse()

func isEqualApprox(to: Vector4) -> bool:
	return vec.is_equal_approx(to)

func isFinite() -> bool:
	return vec.is_finite()

func isNormalized() -> bool:
	return vec.is_normalized()

func isZeroApprox() -> bool:
	return vec.is_zero_approx()

func length() -> float:
	return vec.length()

func lengthSquared() -> float:
	return vec.length_squared()

func lerp(to: Vector4, weight: float) -> Vector4:
	return vec.lerp(to, weight)

func max(with: Vector4) -> Vector4:
	return vec.max(with)

func maxAxisIndex() -> int:
	return vec.max_axis_index()

func maxf(with: float) -> Vector4:
	return vec.maxf(with)

func min(with: Vector4) -> Vector4:
	return vec.min(with)

func minAxisIndex() -> int:
	return vec.min_axis_index()

func minf(with: float) -> Vector4:
	return vec.minf(with)

func normalized() -> Vector4:
	return vec.normalized()

func posmod(mod: float) -> Vector4:
	return vec.posmod(mod)

func posmodv(mod: Vector4) -> Vector4:
	return vec.posmodv(mod)

func round() -> Vector4:
	return vec.round()

func sign() -> Vector4:
	return vec.sign()

func snapped(step: Vector4) -> Vector4:
	return vec.snapped(step)

func snappedf(step: float) -> Vector4:
	return vec.snappedf(step)

func multiply(right) -> Vector4:
	return vec * right

func add(right) -> Vector4:
	return vec + right

func subtract(right) -> Vector4:
	return vec - right

func divide(right) -> Vector4:
	return vec / right

func lessThan(right: Vector4) -> bool:
	return vec < right

func lessThanOrEqualTo(right: Vector4) -> bool:
	return vec <= right

func greaterThan(right: Vector4) -> bool:
	return vec > right

func greaterThanOrEqualTo(right: Vector4) -> bool:
	return vec >= right

func isEqualTo(right: Vector4) -> bool:
	return vec == right
