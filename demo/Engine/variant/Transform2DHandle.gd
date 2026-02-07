extends RefCounted

var xform: Transform2D = Transform2D()

func getX():
	return xform.x

func setZ(value):
	xform.x = value
	return xform.x

func getY():
	return xform.y
	
func setY(value):
	xform.y = value
	return xform.y

func getOrigin():
	return xform.origin

func setOrigin(value):
	xform.origin = value
	return xform.origin

func affineInverse():
	return xform.affine_inverse()

func interpolateWith(pXform, weight):
	return xform.interpolate_with(pXform, weight)

func inverse():
	return xform.inverse()

func isEqualApprox(pXform):
	return xform.is_equal_approx(pXform)

func ifFinite():
	return xform.is_finite()

func lookingAt(target = Vector2(0, 0)):
	return xform.looking_at(target)

func orthonormalized():
	return xform.orthonormalized()

func rotated(angle):
	return xform.rotated(angle)

func rotatedLocal(angle):
	return xform.rotated_local(angle)

func scaled(scale):
	return xform.scaled(scale)

func scaledLocal(scale):
	return xform.scaled_local(scale)

func translated(offset):
	return xform.translated(offset)

func translatedLocal(offset):
	return xform.translated_local(offset)

func multiply(right):
	return xform * right

func add(right):
	return xform + right

func subtract(right):
	return xform - right

func divide(right):
	return xform / right

func lessThan(right) -> bool:
	return xform < right

func lessThanOrEqualTo(right) -> bool:
	return xform <= right

func greaterThan(right) -> bool:
	return xform > right

func greaterThanOrEqualTo(right) -> bool:
	return xform >= right

func isEqualTo(right) -> bool:
	return xform == right
