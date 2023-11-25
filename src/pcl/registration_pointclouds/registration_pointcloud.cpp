#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include <pcl/registration/correspondence_estimation.h>
#include <pcl/registration/transformation_estimation_svd.h>
#include <pcl/common/transforms.h>
#include <Eigen/Dense>
#include <open3d/Open3D.h>
#include <open3d/geometry/PointCloud.h>
#include <open3d/core/EigenConverter.h>
using PointT = pcl::PointXYZI;

void visualizePointclouds(const pcl::PointCloud<PointT>& cloud1,
                          const pcl::PointCloud<PointT>& cloud2) {
    // Convert pcl::PointXYZI to open3d::geometry::PointCloud
    auto pc1 = std::make_shared<open3d::geometry::PointCloud>();
    auto pc2 = std::make_shared<open3d::geometry::PointCloud>();

    pc1->points_.reserve(cloud1.points.size());
    pc1->colors_.reserve(cloud1.points.size());

    pc2->points_.reserve(cloud2.points.size());
    pc2->colors_.reserve(cloud2.points.size());

    // Populate the point clouds with the data from pcl::PointCloud<pcl::PointXYZI>
    for (const auto& point : cloud1.points) {
        pc1->points_ .emplace_back(point.x, point.y, point.z);
        pc1->colors_.emplace_back(1.0,0.0,0.0);
    }
    for (const auto& point : cloud2.points) {
        pc2->points_ .emplace_back(point.x, point.y, point.z);
        pc2->colors_.emplace_back(0.0,1.0,0.0);
    }

    // Create a visualization window
    open3d::visualization::Visualizer visualizer;

    // Add the first point cloud with color red
    visualizer.CreateVisualizerWindow("Open3D - Two Point Clouds", 1280, 720);
    visualizer.AddGeometry(pc1);

    // Add the second point cloud with color blue
    visualizer.AddGeometry(pc2);

    // Set the background color (optional)
    visualizer.GetRenderOption().background_color_ = Eigen::Vector3d(0.0, 0.0, 0.0);

    // Update the visualization
    visualizer.UpdateGeometry();
    visualizer.PollEvents();
    visualizer.UpdateRender();

    // Keep the window open until it is closed by the user
    visualizer.Run();
}
void DoRegistration(const pcl::PointCloud<PointT>& source_point_cloud,const pcl::PointCloud<PointT>& target_point_cloud)
{
  pcl::PointCloud<PointT>::Ptr source(new pcl::PointCloud<PointT>);
  pcl::PointCloud<PointT>::Ptr target(new pcl::PointCloud<PointT>);
  *source = source_point_cloud;
  *target = target_point_cloud;

  pcl::registration::CorrespondenceEstimation<PointT,PointT> estimation;
  estimation.setInputSource(source);
  estimation.setInputTarget(target);

    pcl::Correspondences correspondences;

    // Compute correspondences
    estimation.determineCorrespondences(correspondences,1.0F);

    pcl::registration::TransformationEstimationSVD<PointT , PointT> transformation_estimation;

    // Create a 4x4 matrix to store the transformation
    Eigen::Matrix4f transformation_matrix;

    // Estimate the transformation matrix from correspondences
    transformation_estimation.estimateRigidTransformation(*source, *target, correspondences, transformation_matrix);

    // Output the transformation matrix
    std::cout << "Transformation Matrix:" << std::endl << transformation_matrix << std::endl;
    // Transform the PointCloud using the transformation matrix
    pcl::PointCloud<PointT> transformed_cloud;
    pcl::transformPointCloud(*source, transformed_cloud, transformation_matrix);
    visualizePointclouds(transformed_cloud,target_point_cloud);
}



int main (int argc , char *argv[])
{
  boost::filesystem::path input_source_pointcloud;
  boost::filesystem::path input_target_pointcloud;
  boost::filesystem::path output_point_cloud_location;

  boost::program_options::options_description desc{"Allowed options"};

  desc.add_options()("help,h", "produce help message")  //
      ("input-source-pointcloud",
       boost::program_options::value<boost::filesystem::path>(&input_source_pointcloud)
           ->default_value("src/pcl/registration_pointclouds/source_pointcloud.pcd"),
       "source pointcloud")  //
      ("input-target-pointcloud",
       boost::program_options::value<boost::filesystem ::path>(&input_target_pointcloud)
           ->default_value("src/pcl/registration_pointclouds/target_pointcloud.pcd"),
       "target pointcloud")("output-point-cloud-location",
                                        boost::program_options::value<boost::filesystem ::path>(&output_point_cloud_location)
                                            ->default_value("src/pcl/registration_pointclouds/"),
                                        "Set path to point cloud store");

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  std::cout << "input_bag_location " << input_source_pointcloud << '\n';
  std::cout << "output_json_location " << input_target_pointcloud << '\n';
  std::cout << "output_point_cloud_location " << output_point_cloud_location << '\n';


  if (vm.count("help") != 0) {
    std::cout << desc << "\n";
    return EXIT_FAILURE;
  }

  pcl::PointCloud<PointT> input_source_points;
  pcl::PointCloud<PointT> input_target_points;

  if (pcl::io::loadPCDFile<PointT> (input_source_pointcloud.string(),input_source_points) == -1) //* load the file
  {
    std::cerr<<"Couldn't read file input_source_pointcloud \n";
    return EXIT_FAILURE;
  }

  if (pcl::io::loadPCDFile<PointT> (input_target_pointcloud.string(),input_target_points) == -1) //* load the file
  {
    std::cerr<<"Couldn't read file input_target_pointcloud \n";
    return EXIT_FAILURE;
  }

  std::cout << "Loaded " << input_source_points.points.size() << " data points from "<< input_source_pointcloud<< std::endl;
  std::cout << "Loaded " << input_target_points.points.size() << " data points from "   <<input_target_pointcloud <<std::endl;

  DoRegistration(input_source_points,input_target_points);

  return 0;
}