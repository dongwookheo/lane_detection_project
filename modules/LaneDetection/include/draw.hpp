/**
 * @file draw.hpp
 * @author Nahye Kim (nahelove03@gmail.com) Dongwook Heo (hdwook3918@gmail.com)
 * @brief Provides functions for drawing lines and rectangles on image frames in the XyCar namespace.
 * @version 1.0.0
 * @date 2023-11-10
 * @copyright Copyright (c) 2023 I_On_Car, All Rights Reserved.
 */
#ifndef LANE_DETECTION__DRAW_HPP
#define LANE_DETECTION__DRAW_HPP

// Third party header
#include "opencv2/opencv.hpp"
// User defined header
#include "Common.hpp"

namespace XyCar
{
/**
 * @brief Draw a line with slope on 'frame'.
 * @details This function draws a line with slope on 'frame'.
 * @param[out] frame The frame of an image.
 * @param[in] slope The slope of a lane.
 * @param[in] intercept The intercept of a lane.
 * @param[in] color The color of lane.
 * @return void
 */
void draw_line_slope(cv::Mat &frame, PREC slope, PREC intercept, const cv::Scalar &color, int32_t k_frame_height)
{
  if (slope == 0)
    return;

  int32_t y1 = k_frame_height;
  int32_t y2 = std::round(y1 >> 1);
  int32_t x1 = std::round((y1 - intercept) / slope);
  int32_t x2 = std::round((y2 - intercept) / slope);

  cv::line(frame, cv::Point(x1, y1), cv::Point(x2, y2), color, 2, cv::LINE_8);
}

/**
 * @brief Draw a line using coordinates(point1, point2) on 'frame'.
 * @details This function draws a line using coordinates(point1, point2) on 'frame'.
 * @param[out] frame The frame of an image.
 * @param[in] point1 The first point defining the line.
 * @param[in] point2 The second point defining the line.
 * @param[in] color The color of lane.
 * @return void
 */
void draw_line_points(cv::Mat &frame, cv::Point point1, cv::Point point2, const cv::Scalar &color)
{
  cv::line(frame, point1, point2, color, 2, cv::LINE_8);
}

/**
 * @brief Draw a rectangle on 'frame'.
 * @details This function draws a rectangle using coordinates(pos) on 'frame'.
 * @param[out] frame The frame of an image.
 * @param[in] pos The x-coordinate of the rectangle.
 * @return void
 */
void draw_rectangle(cv::Mat &frame, int32_t pos, const cv::Scalar &color, uint32_t k_offset)
{
  cv::rectangle(frame, cv::Rect(cv::Point(pos - 7, k_offset - 7), cv::Point(pos + 7, k_offset + 7)), color, 2);
}
} // namespace XyCar

#endif // LANE_DETECTION__DRAW_HPP
