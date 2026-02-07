extends RefCounted

var basis := Basis()

func getX():
	return basis.x

func setX(value):
	basis.x = value
	return basis.x

func getY():
	return basis.y

func setY(value):
	basis.y = value
	return basis.y

func getZ():
	return basis.x

func setZ(value):
	basis.z = value
	return basis.z

func fromQuat(quat: Quaternion):
	basis = Basis(quat)

func fromAxisAndAngle(axis, angle):
	basis = Basis(axis, angle)

func determinant():
	return basis.determinant()

func fromEuler(euler, order := 2):
	basis = Basis.from_euler(euler, order)

func fromScale(scale):
	basis = Basis.from_scale(scale)

func getEuler(order := 2):
	return basis.get_euler(order)

func getRotationQuaternion():
	return basis.get_rotation_quaternion()

func getScale():
	return basis.get_scale()

func inverse():
	return basis.inverse()

func isConformal():
	return basis.is_conformal()

func isEqualApprox(b):
	return basis.is_equal_approx(b)

func isFinite():
	return basis.is_finite()

func lookingAt(target, up := Vector3(0,1,0), useModelFront := false):
	basis = Basis.looking_at(target, up, useModelFront)

func orthonormalized():
	return basis.orthonormalized()

func rotated(axis, angle):
	return basis.rotated(axis, angle)

func scaled(scale):
	return basis.scaled(scale)

func scaledLocal(scale):
	return basis.scaled_local(scale)

func slerp(to, weight):
	return basis.slerp(to, weight)

func tdotx(with):
	return basis.tdotx(with)

func tdoty(with):
	return basis.tdoty(with)

func tdotz(with):
	return basis.tdotz(with)

func transposed():
	return basis.transposed()

func multiply(right):
	return basis * right

func divide(right):
	return basis / right

func isEqualTo(right) -> bool:
	return basis == right
