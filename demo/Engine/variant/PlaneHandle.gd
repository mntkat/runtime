extends RefCounted

var plane := Plane()

func getD():
	return plane.d

func setD(value):
	plane.d = value
	return plane.d

func getNormal():
	return plane.normal

func setNormal(value):
	plane.normal = value
	return plane.normal

func getX():
	return plane.x

func setX(value):
	plane.x = value
	return plane.x

func getY():
	return plane.y

func setY(value):
	plane.y = value
	return plane.y

func getZ():
	return plane.x

func setZ(value):
	plane.z = value
	return plane.z

func fromABCD(a, b, c, d):
	plane = Plane(a, b, c, d)

func from(point1, point2, point3):
	plane = Plane(point1, point2, point3)

func distanceTo(point):
	return plane.distance_to(point)

func getCenter():
	return plane.get_center()

func hasPoint(point, tolerance := 1e-05):
	return plane.has_point(point, tolerance)

func intersect3(b, c):
	return plane.intersect_3(b, c)

func intersectsRay(pFrom, dir):
	return plane.intersects_ray(pFrom, dir)

func intersectsSegment(pFrom, to):
	return plane.intersects_segment(pFrom, to)

func isEqualApprox(toPlane):
	return plane.is_equal_approx(toPlane)

func isFinite():
	return plane.is_finite()

func isPointOver(point):
	return plane.is_point_over(point)

func normalized():
	return plane.normalized()

func project(point):
	return plane.project(point)

func multiply(right):
	return plane * right

func isEqualTo(right) -> bool:
	return plane == right
