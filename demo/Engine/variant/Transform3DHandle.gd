extends RefCounted

var xform: Transform3D = Transform3D()

func getBasis() -> Basis:
	return xform.basis

func setBasis(value: Basis) -> Basis:
	xform.basis = value
	return xform.basis

func getOrigin() -> Vector3:
	return xform.origin

func setOrigin(value: Vector3) -> Vector3:
	xform.origin = value
	return xform.origin

func fromXYZAxisAndOrigin(xAxis, yAxis, zAxis, origin):
	xform = Transform3D(xAxis, yAxis, zAxis, origin)

func fromProjection(proj: Projection):
	xform = Transform3D(proj)

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

func lookingAt(target, up = Vector3(0, 1, 0), useModelFront = false):
	return xform.looking_at(target, up, useModelFront)

func orthonormalized():
	return xform.orthonormalized()

func rotated(axis, angle):
	return xform.rotated(axis, angle)

func rotatedLocal(axis, angle):
	return xform.rotated_local(axis, angle)

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
