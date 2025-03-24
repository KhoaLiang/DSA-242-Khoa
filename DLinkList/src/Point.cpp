#include "util/Point.h"

ostream& operator<<(ostream& os, const Point& point) {
  os << "P(" << fixed << setprecision(1) << point.x << ", " << setprecision(1)
     << point.y << ", " << setprecision(1) << point.z << ")";
  return os;
}

// Constructor
Point::Point(float x, float y, float z) : x(x), y(y), z(z) {}

// Copy constructor
Point::Point(const Point& point) : x(point.x), y(point.y), z(point.z) {}

// Setter for x
void Point::setX(float x) { this->x = x; }

// Getter for x
float Point::getX() const { return x; }

// Setter for y
void Point::setY(float y) { this->y = y; }

// Getter for y
float Point::getY() const { return y; }

// Setter for z
void Point::setZ(float z) { this->z = z; }

// Getter for z
float Point::getZ() const { return z; }

// Calculate radius
float Point::radius() const { return std::sqrt(x * x + y * y + z * z); }

// Conversion operator to float, returns the radius
Point::operator float() { return this->radius(); }

// Overload the equality operator
bool Point::operator==(Point rhs) const {
  return std::abs(x - rhs.x) < EPSILON && std::abs(y - rhs.y) < EPSILON &&
         std::abs(z - rhs.z) < EPSILON;
}

// Comparison functions for non-pointer types
bool Point::pointEQ_X(Point& lhs, Point& rhs) {
  return std::abs(lhs.x - rhs.x) < EPSILON;
}

bool Point::pointEQ_Y(Point& lhs, Point& rhs) {
  return std::abs(lhs.y - rhs.y) < EPSILON;
}

bool Point::pointEQ_Z(Point& lhs, Point& rhs) {
  return std::abs(lhs.z - rhs.z) < EPSILON;
}

bool Point::pointEQ_Radius(Point& lhs, Point& rhs) {
  return std::abs(lhs.radius() - rhs.radius()) < EPSILON;
}

bool Point::pointEQ(Point& lhs, Point& rhs) {
  return pointEQ_X(lhs, rhs) && pointEQ_Y(lhs, rhs) && pointEQ_Z(lhs, rhs);
}

// Comparison functions for pointer types
bool Point::pointEQ_X(Point*& lhs, Point*& rhs) {
  return pointEQ_X(*lhs, *rhs);
}

bool Point::pointEQ_Y(Point*& lhs, Point*& rhs) {
  return pointEQ_Y(*lhs, *rhs);
}

bool Point::pointEQ_Z(Point*& lhs, Point*& rhs) {
  return pointEQ_Z(*lhs, *rhs);
}

bool Point::pointEQ_Radius(Point*& lhs, Point*& rhs) {
  return pointEQ_Radius(*lhs, *rhs);
}

bool Point::pointEQ(Point*& lhs, Point*& rhs) { return pointEQ(*lhs, *rhs); }

// Conversion to string functions for non-pointer types
string Point::point2str_X(Point& point) {
  std::stringstream ss;
  ss << "X: " << point.x;
  return ss.str();
}

string Point::point2str_Y(Point& point) {
  std::stringstream ss;
  ss << "Y: " << point.y;
  return ss.str();
}

string Point::point2str_Z(Point& point) {
  std::stringstream ss;
  ss << "Z: " << point.z;
  return ss.str();
}

string Point::point2str_Radius(Point& point) {
  std::stringstream ss;
  ss << "Radius: " << point.radius();
  return ss.str();
}

string Point::point2str(Point& point) {
  std::stringstream ss;
  ss << "P(" << point.x << ", " << point.y << ", " << point.z << ")";
  return ss.str();
}

// Conversion to string functions for pointer types
string Point::point2str_X(Point*& point) { return point2str_X(*point); }

string Point::point2str_Y(Point*& point) { return point2str_Y(*point); }

string Point::point2str_Z(Point*& point) { return point2str_Z(*point); }

string Point::point2str_Radius(Point*& point) {
  return point2str_Radius(*point);
}

string Point::point2str(Point*& point) { return point2str(*point); }

// Remove a point object
void Point::pointRemove(Point* point) { delete point; }

// Generate points (stub for future implementation)
Point* Point::genPoints(int size, float minValue, float maxValue,
                        bool manualSeed, int seedValue) {
  Point* points = new Point[size];
  // Implement point generation logic here
  return points;
}

// Print a list of points
void Point::println(Point* head, int size) {
  stringstream os;
  os << "[";
  for (int idx = 0; idx < size - 1; idx++) {
    os << head[idx] << ", ";
  }
  if (size > 0)
    os << head[size - 1] << "]";
  else
    os << "]";
  cout << os.str() << endl;
}
