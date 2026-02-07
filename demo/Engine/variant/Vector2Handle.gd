extends RefCounted

var vec: Vector2 = Vector2()

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

func abs() -> Vector2:
	return vec.abs()

func angle() -> float:
	return vec.angle()

func angleTo(to: Vector2) -> float:
	return vec.angle_to(to)

func angleToPoint(to: Vector2) -> float:
	return vec.angle_to_point(to)

func aspect() -> float:
	return vec.aspect()

func bezierDerivative(control1: Vector2, control2: Vector2, end: Vector2, t: float) -> Vector2:
	return vec.bezier_derivative(control1, control2, end, t)

func bezierInterpolate(control1: Vector2, control2: Vector2, end: Vector2, t: float) -> Vector2:
	return vec.bezier_interpolate(control1, control2, end, t)

func bounce(n: Vector2) -> Vector2:
	return vec.bounce(n)

func ceil() -> Vector2:
	return vec.ceil()

func clamp(pMin: Vector2, pMax: Vector2) -> Vector2:
	return vec.clamp(pMin, pMax)

func clampf(pMin: float, pMax: float) -> Vector2:
	return vec.clampf(pMin, pMax)

func cross(with: Vector2) -> float:
	return vec.cross(with)

func cubicInterpolate(b: Vector2, preA: Vector2, postB: Vector2, weight: float) -> Vector2:
	return vec.cubic_interpolate(b, preA, postB, weight)

func cubicInterpolateInTime(b: Vector2, preA: Vector2, postB: Vector2, weight: float, bT: float, preAT: float, postBT: float) -> Vector2:
	return vec.cubic_interpolate_in_time(b, preA, postB, weight, bT, preAT, postBT)

func directionTo(to: Vector2) -> Vector2:
	return vec.direction_to(to)

func distanceDquaredTo(to: Vector2) -> float:
	return vec.distance_squared_to(to)

func distanceTo(to: Vector2) -> float:
	return vec.distance_to(to)

func dot(with: Vector2) -> float:
	return vec.dot(with)

func floor() -> Vector2:
	return vec.floor()

func isEqualApprox(to: Vector2) -> bool:
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

func lerp(to: Vector2, weight: float) -> Vector2:
	return vec.lerp(to, weight)

func limitLength(pLength: float = 1.0) -> Vector2:
	return vec.limit_length(pLength)

func max(with: Vector2) -> Vector2:
	return vec.max(with)

func maxAxisIndex() -> int:
	return vec.max_axis_index()

func maxf(with: float) -> Vector2:
	return vec.maxf(with)

func min(with: Vector2) -> Vector2:
	return vec.min(with)

func minAxisIndex() -> int:
	return vec.min_axis_index()

func minf(with: float) -> Vector2:
	return vec.minf(with)

func moveToward(to: Vector2, delta: float) -> Vector2:
	return vec.move_toward(to, delta)

func normalized() -> Vector2:
	return vec.normalized()

func orthogonal() -> Vector2:
	return vec.orthogonal()

func posmod(mod: float) -> Vector2:
	return vec.posmod(mod)

func posmodv(mod: Vector2) -> Vector2:
	return vec.posmodv(mod)

func project(b: Vector2) -> Vector2:
	return vec.project(b)

func reflect(n: Vector2) -> Vector2:
	return vec.reflect(n)

func round() -> Vector2:
	return vec.round()

func sign() -> Vector2:
	return vec.sign()

func slerp(to: Vector2, weight: float) -> Vector2:
	return vec.slerp(to, weight)

func slide(n: Vector2) -> Vector2:
	return vec.slide(n)

func snapped(step: Vector2) -> Vector2:
	return vec.snapped(step)

func snappedf(step: float) -> Vector2:
	return vec.snappedf(step)

func multiply(right) -> Vector2:
	return vec * right

func add(right) -> Vector2:
	return vec + right

func subtract(right) -> Vector2:
	return vec - right

func divide(right) -> Vector2:
	return vec / right

func lessThan(right: Vector2) -> bool:
	return vec < right

func lessThanOrEqualTo(right: Vector2) -> bool:
	return vec <= right

func greaterThan(right: Vector2) -> bool:
	return vec > right

func greaterThanOrEqualTo(right: Vector2) -> bool:
	return vec >= right

func isEqualTo(right: Vector2) -> bool:
	return vec == right
