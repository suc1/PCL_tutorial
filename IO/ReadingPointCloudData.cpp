#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main ()
 {
   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
 
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("./data/test_pcd.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  /*    PCL 1.x
    pcl::PCLPointCloud2 cloud_blob;
    pcl::io::loadPCDFile ("test_pcd.pcd", cloud_blob);
    pcl::fromPCLPointCloud2 (cloud_blob, *cloud); //* convert from pcl/PCLPointCloud2 to pcl::PointCloud<T>
  */

  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  
  for (const auto& point: *cloud)
    std::cout << "    " << point.x
              << " "    << point.y
              << " "    << point.z << std::endl;

  return (0);
}
