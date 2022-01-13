//
// Created by Alexander Shagarov on 12/01/2022.
//

#include "image.h"
#include "misc.h"

void image::save(std::ostream &out) const {
    out << "P3\n"
              << Width << " " << Height << "\n"
              << "255\n";

    for (int j = Height - 1; j >= 0; --j) {
        for (int i = 0; i < Width; ++i) {
            const auto &pixel = at(i, j);
            out
                    << static_cast<int>(256 * clamp(pixel.x(), 0, 0.999)) << " "
                    << static_cast<int>(256 * clamp(pixel.y(), 0, 0.999)) << " "
                    << static_cast<int>(256 * clamp(pixel.z(), 0, 0.999)) << "\n";
        }
    }
}

const color &image::at(int x, int y) const {
    return Data[x + Width * y];
}

color &image::at(int x, int y) {
    return Data[x + Width * y];
}
