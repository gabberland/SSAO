// Author: Marc Comino 2020

#ifndef TRIANGLE_MESH_H_
#define TRIANGLE_MESH_H_

#include <eigen3/Eigen/Geometry>

#include <vector>

namespace data_representation {

class TriangleMesh {
 public:
  /**
   * @brief TriangleMesh Constructor of the class. Calls clear.
   */
  TriangleMesh();

  /**
   * @brief ~TriangleMesh Destructor of the class.
   */
  ~TriangleMesh() {}

  /**
   * @brief Clear Empties the data arrays and resets the bounding box vertices.
   */
  void Clear();

 public:

  std::vector<int> faces_;
  std::vector<float> vertices_;
  std::vector<float> normals_;

  unsigned int VAO, VBO, VBO2, EBO;

  /**
   * @brief min The minimum point of the bounding box.
   */
  Eigen::Vector3f min_;

  /**
   * @brief max The maximum point of the bounding box.
   */
  Eigen::Vector3f max_;

  void setUpMesh();

  private:
    /*  Render data  */
};

}  // namespace data_representation

#endif  //  TRIANGLE_MESH_H_
