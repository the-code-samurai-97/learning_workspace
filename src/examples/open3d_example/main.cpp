#include <open3d/Open3D.h>

int main() {
    // Load a sample point cloud (replace "your_point_cloud.pcd" with your actual file)
    auto point_cloud = open3d::io::CreatePointCloudFromFile("src/examples/open3d_example/source_pointcloud.pcd");

    // Visualize the point cloud
    open3d::visualization::DrawGeometries({point_cloud});

    return 0;
}
