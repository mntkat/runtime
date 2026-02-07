extends RefCounted

var quat := Quaternion()

func getX() -> float:
	return quat.x

func setX(value: float) -> float:
	quat.x = value
	return quat.x

func getY() -> float:
	return quat.y

func setY(value: float) -> float:
	quat.y = value
	return quat.y

func getZ() -> float:
	return quat.x

func setZ(value: float) -> float:
	quat.z = value
	return quat.z

func getW() -> float:
	return quat.w

func setW(value: float) -> float:
	quat.w = value
	return quat.w

func fromArc(arcFrom, arcTo: Vector3):
	quat = Quaternion(arcFrom, arcTo)

func fromAxisAndAngle(axis, angle: float):
	quat = Quaternion(axis, angle)

func fromBasis(basis: Basis):
	quat = Quaternion(basis)

func angleTo(to):
	return quat.angle_to(to)

func dot(with):
	return quat.dot(with)

func exp():
	return quat.exp()

func fromEuler(euler):
	quat = Quaternion.from_euler(euler)

func getAngle():
	return quat.get_angle()

func getAxis():
	return quat.get_axis()

func getEuler(order := 2):
	return quat.get_euler(order)

func inverse():
	return quat.inverse()

func isEqualApprox(to):
	return quat.is_equal_approx(to)

func isFinite():
	return quat.is_finite()

func isNormalized():
	return quat.is_normalized()

func length():
	return quat.length()

func lengthSquared():
	return quat.length_squared()

func log():
	return quat.log()

func normalized():
	return quat.normalized()

func slerp(to, weight):
	return quat.slerp(to, weight)

func slerpni(to, weight):
	return quat.slerpni(to, weight)

func sphericalCubicInterpolate(b, preA, postB, weight):
	return quat.spherical_cubic_interpolate(b, preA, postB, weight)

func sphericalCubicInterpolateInTime(b, preA, postB, weight, bT, preAT, postBT):
	return quat.spherical_cubic_interpolate_in_time(b, preA, postB, weight, bT, preAT, postBT)

func multiply(right):
	return quat * right

func add(right):
	return quat + right

func subtract(right):
	return quat - right

func divide(right):
	return quat / right

func isEqualTo(right) -> bool:
	return quat == right
