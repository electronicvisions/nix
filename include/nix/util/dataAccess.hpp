// Copyright (c) 2013, German Neuroinformatics Node (G-Node)
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted under the terms of the BSD License. See
// LICENSE file in the root of the Project.

/**
 * @namespace nix::util
 * @brief Namespace for utility functions. This namespace is not part of the public API.
 */

#ifndef NIX_DATAACCESS_H
#define NIX_DATAACCESS_H

#include <nix/NDArray.hpp>
#include <nix/DataView.hpp>
#include <nix/Dimensions.hpp>
#include <nix/DataArray.hpp>
#include <nix/MultiTag.hpp>
#include <nix/Tag.hpp>

#include <ctime>

namespace nix {
namespace util {

/**
 * @brief Converts a position given in a unit into an index according to the dimension descriptor.
 *
 * This function can be used to get the index of e.g. a certain point in time in a Dimension that
 * represents time. The units of the position and that provided by the Dimension must match, i.e.
 * must be scalable versions of the same SI unit.
 *
 * @param position      The position
 * @param unit          The unit in which the position is given, may be "none"
 * @param dimension     The dimension descriptor for the respective dimension.
 *
 * @return The calculated index.
 *
 * @throws nix::IncompatibleDimension The the dimensions are incompatible.
 * @throws nix::OutOfBounds If the position either too large or too small for the dimension.
 */
NIXAPI ndsize_t positionToIndex(double position, const std::string &unit, const SetDimension &dimension);

/**
 * @brief Converts a position given in a unit into an index according to the dimension descriptor.
 *
 * This function can be used to get the index of e.g. a certain point in time in a Dimension that
 * represents time. The units of the position and that provided by the Dimension must match, i.e.
 * must be scalable versions of the same SI unit.
 *
 * @param position      The position
 * @param unit          The unit in which the position is given, may be "none"
 * @param dimension     The dimension descriptor for the respective dimension.
 *
 * @return The calculated index.
 *
 * @throws nix::IncompatibleDimension The the dimensions are incompatible.
 * @throws nix::OutOfBounds If the position either too large or too small for the dimension.
 */
NIXAPI ndsize_t positionToIndex(double position, const std::string &unit, const SampledDimension &dimension);

/**
 * @brief Converts a position given in a unit into an index according to the dimension descriptor.
 *
 * This function can be used to get the index of e.g. a certain point in time in a Dimension that
 * represents time. The units of the position and that provided by the Dimension must match, i.e.
 * must be scalable versions of the same SI unit.
 *
 * @param position      The position
 * @param unit          The unit in which the position is given, may be "none"
 * @param dimension     The dimension descriptor for the respective dimension.
 *
 * @return The calculated index.
 *
 * @throws nix::IncompatibleDimension The the dimensions are incompatible.
 * @throws nix::OutOfBounds If the position either too large or too small for the dimension.
 */
NIXAPI ndsize_t positionToIndex(double position, const std::string &unit, const RangeDimension &dimension);

/**
 * @brief Returns the offsets and element counts associated with position and extent of a Tag and
 *        the referenced DataArray.
 *
 * @param tag           The tag.
 * @param array         A referenced data array.
 * @param[out] offsets  The resulting offset.
 * @param[out] counts   The number of elements to read from data
 */
NIXAPI void getOffsetAndCount(const Tag &tag, const DataArray &array, NDSize &offsets, NDSize &counts);


NIXAPI void getOffsetAndCount(const MultiTag &tag, const DataArray &array, ndsize_t index, NDSize &offsets, NDSize &counts);

/**
 * @brief Retrieve the data referenced by the given position and extent of the MultiTag.
 *
 * @param tag                   The multi tag.
 * @param position_index        The index of the position.
 * @param reference_index       The index of the reference from which data should be returned.
 *
 * @return The data referenced by position and extent.
 */
NIXAPI DataView retrieveData(const MultiTag &tag, ndsize_t position_index, size_t reference_index);

/**
 * @brief Retrieve the data referenced by the given position and extent of the Tag.
 *
 * @param tag                   The multi tag.
 * @param reference_index       The index of the reference from which data should be returned.
 *
 * @return The data referenced by the position.
 */
NIXAPI DataView retrieveData(const Tag &tag, size_t reference_index);

/**
 * @brief Checks whether a given position is in the extent of the given DataArray.
 *
 * @param data          The data array.
 * @param position      The position.
 *
 * @return True if the position is in the extent of the data array, false otherwise.
 */
NIXAPI bool positionInData(const DataArray &data, const NDSize &position);

/**
 * @brief Checks whether a given position plus count is in the extent of the given DataArray.
 *
 * @param data          The DataArray.
 * @param position      The position
 * @param count         The number of elements per dimension.
 *
 * @return True if position and count are in the extent of the data array, false otherwise.
 */
NIXAPI bool positionAndExtentInData(const DataArray &data, const NDSize &position, const NDSize &count);

/**
 * @brief Retruns the feature data associated with a Tag.
 *
 * @param tag           The Tag whos feature data is requested
 * @param feature_index The index of the desired feature. Default is 0.
 *
 * @return The associated data.
 */
NIXAPI DataView retrieveFeatureData(const Tag &tag, size_t feature_index=0);

/**
 * @brief Returns the feature data accosiated with the given MuliTag's position.
 *
 * @param tag            The MultiTag whos feature data is requested.
 * @param position_index The index of the selected position, respectively the selected tag of the MultiTag.
 * @param feature_index  The index of the desired feature. Default is 0.
 *
 * @return The associated data.
 */
NIXAPI DataView retrieveFeatureData(const MultiTag &tag, ndsize_t position_index, size_t feature_index=0);

}
}
#endif // NIX_DATAACCESS_H
