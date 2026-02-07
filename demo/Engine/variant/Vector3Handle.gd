extends RefCounted

var vec: Vector3 = Vector3()

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

func abs() -> Vector3:
	return vec.abs()

func angleTo(to: Vector3) -> float:
	return vec.angle_to(to)

func bezierDerivative(control1: Vector3, control2: Vector3, end: Vector3, t: float) -> Vector3:
	return vec.bezier_derivative(control1, control2, end, t)

func bezierInterpolate(control1: Vector3, control2: Vector3, end: Vector3, t: float) -> Vector3:
	return vec.bezier_interpolate(control1, control2, end, t)

func bounce(n: Vector3) -> Vector3:
	return vec.bounce(n)

func ceil() -> Vector3:
	return vec.ceil()

func clamp(pMin: Vector3, pMax: Vector3) -> Vector3:
	return vec.clamp(pMin, pMax)

func clampf(pMin: float, pMax: float) -> Vector3:
	return vec.clampf(pMin, pMax)

func cross(with: Vector3) -> Vector3:
	return vec.cross(with)

func cubicInterpolate(b: Vector3, preA: Vector3, postB: Vector3, weight: float) -> Vector3:
	return vec.cubic_interpolate(b, preA, postB, weight)

func cubicInterpolateInTime(b: Vector3, preA: Vector3, postB: Vector3, weight: float, bT: float, preAT: float, postBT: float) -> Vector3:
	return vec.cubic_interpolate_in_time(b, preA, postB, weight, bT, preAT, postBT)

func directionTo(to: Vector3) -> Vector3:
	return vec.direction_to(to)

func distanceDquaredTo(to: Vector3) -> float:
	return vec.distance_squared_to(to)

func distanceTo(to: Vector3) -> float:
	return vec.distance_to(to)

func dot(with: Vector3) -> float:
	return vec.dot(with)

func floor() -> Vector3:
	return vec.floor()

func inverse() -> Vector3:
	return vec.inverse()

func isEqualApprox(to: Vector3) -> bool:
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

func lerp(to: Vector3, weight: float) -> Vector3:
	return vec.lerp(to, weight)

func limitLength(pLength: float = 1.0) -> Vector3:
	return vec.limit_length(pLength)

func max(with: Vector3) -> Vector3:
	return vec.max(with)

func maxAxisIndex() -> int:
	return vec.max_axis_index()

func maxf(with: float) -> Vector3:
	return vec.maxf(with)

func min(with: Vector3) -> Vector3:
	return vec.min(with)

func minAxisIndex() -> int:
	return vec.min_axis_index()

func minf(with: float) -> Vector3:
	return vec.minf(with)

func moveToward(to: Vector3, delta: float) -> Vector3:
	return vec.move_toward(to, delta)

func normalized() -> Vector3:
	return vec.normalized()

func octahedronDecode(uv: Vector2) -> void:
	vec = Vector3.octahedron_decode(uv)

func octahedronEncode() -> Vector2:
	return vec.octahedron_encode()

func outer(with: Vector3) -> Basis:
	return vec.outer(with)

func posmod(mod: float) -> Vector3:
	return vec.posmod(mod)

func posmodv(mod: Vector3) -> Vector3:
	return vec.posmodv(mod)

func project(b: Vector3) -> Vector3:
	return vec.project(b)

func reflect(n: Vector3) -> Vector3:
	return vec.reflect(n)

func rotated(axis: Vector3, angle: float) -> Vector3:
	return vec.rotated(axis, angle)

func round() -> Vector3:
	return vec.round()

func sign() -> Vector3:
	return vec.sign()

func signedAngleTo(to: Vector3, axis: Vector3) -> float:
	return vec.signed_angle_to(to, axis)

func slerp(to: Vector3, weight: float) -> Vector3:
	return vec.slerp(to, weight)

func slide(n: Vector3) -> Vector3:
	return vec.slide(n)

func snapped(step: Vector3) -> Vector3:
	return vec.snapped(step)

func snappedf(step: float) -> Vector3:
	return vec.snappedf(step)

func multiply(right) -> Vector3:
	return vec * right

func add(right) -> Vector3:
	return vec + right

func subtract(right) -> Vector3:
	return vec - right

func divide(right) -> Vector3:
	return vec / right

func lessThan(right: Vector3) -> bool:
	return vec < right

func lessThanOrEqualTo(right: Vector3) -> bool:
	return vec <= right

func greaterThan(right: Vector3) -> bool:
	return vec > right

func greaterThanOrEqualTo(right: Vector3) -> bool:
	return vec >= right

func isEqualTo(right: Vector3) -> bool:
	return vec == right
