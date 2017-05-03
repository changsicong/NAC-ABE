/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2017, Regents of the University of California.
 *
 * This file is part of ndnabac, a certificate management system based on NDN.
 *
 * ndnabac is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * ndnabac is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received copies of the GNU General Public License along with
 * ndnabac, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndnabac authors and contributors.
 */

#ifndef NDNABAC_ATTRIBUTE_AUTHORITY_HPP
#define NDNABAC_ATTRIBUTE_AUTHORITY_HPP

#include "ndnabac-common.hpp"
#include <stdarg.h>

namespace ndn {
namespace ndnabac {

class AttributeAuthority
{
public:
  AttributeAuthority(Face& m_face);

  void
  onDecryptionKeyRequest(const Interest& interest);

  void
  onPublicParamsRequest(const Interest& interest);

  algo::PrivateKey
  issueDecryptionKey(const std::list<std::string>& attrList);

  bool
  createKey(const std::string keyName, ...);

private:
  void
  filterAndServe(const InterestFilter& forwardingHint, const Interest& interest);

  void
  cpabeSetup();

  void
  cpabaKeygen(const std::string keyName, ...);

private:
  Face& m_face;
  algo::PublicParams m_pubParams;
  algo::MasterKey m_masterKey;
};

} // namespace ndnabac
} // namespace ndn

#endif // NDNABAC_ATTRIBUTE_AUTHORITY_HPP
