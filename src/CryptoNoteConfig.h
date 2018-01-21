// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x16fa;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 20;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2500000000000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                   = 69500; // HF Zawy
const size_t ZAWY_DIFFICULTY_V2                              = 0;
const size_t ZAWY_DIFFICULTY_V3                          	 = 0;
const size_t ZAWY_DIFFICULTY_V4                              = 0;
const uint8_t ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION       = 0;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 20000; // size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 60000; // increasing to allow bigger tx
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(5000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(5000);

const uint64_t DIFFICULTY_TARGET                             = 175; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V1                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2                          = 60;
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG                                = 15;  // set to 15 to match iridium_v2
const size_t   DIFFICULTY_LAG_V1                             = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2                             = 0;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 8560;
const uint32_t IRIDIUM_REWARD_ADJUSTMENT_BLOCK               = 8560;

const uint32_t UPGRADE_HEIGHT_V2                             = 69500;
const uint32_t UPGRADE_HEIGHT_V3                             = 99999999;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "iridium";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  12007;
const int      RPC_DEFAULT_PORT                              =  13007;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

const char* const SEED_NODES[] = {"192.243.102.175:12007", "192.243.102.176:12007", "164.132.45.97:12007"};


struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
     {1100,"afdbee5a9f28a4c0a78d6a18dbac793e51e2776fece60848954b8e1ec160cda1"},
     {1472,"c04eeed2a0472ed73a5a42e14834cbb82ff35dae555df343d1d5abcac0dc0c19"},
     {1473,"1571fe8ab50ec2d7c3a523f939524086408c9e9f1fadad820d8af50bbf4ec1dc"},
     {1474,"72d9313ed27985756ec2be9d524aee16026c2f8c5b48c2ea9886a88334019b8d"},
     {2200,"5e7e150df20e63be205f06c6a6f729f7b46c747229acf2e667485b0d2639c649"},
     {3300,"791928b5c3c89cee8ada3b289b5ae1fd85a1a023b10b2c932278860f60e10ad4"},
     {4400,"c2f768a5ddc200a26498069785d0b7044f7fb7a899ed9c60c99e3808eea7ff18"},
     {5500,"bf0b357c23d4924a29b9336ea68302e3c058d44ff25153e5e717198874201df3"},
     {6600,"19be10beebd3b587acbd2b4604d7bfe775e1b7641dde36f67f0f8cb156f9ff38"},
     {7700,"def4a690c95f49ffb963504773d575b3979adc77a314f24966f0aa95e03aec3c"},
     {8800,"2bd79ba2a0fc988f902e0353ce41adaebe7e707082945eb87dd5841c9ca47ed1"},
     {9900,"8eea03ce377015ba5c069c56581c237b4a600b525b60137b8f13b748cd7116e8"},
     {10100,"81e9f16a8e36266fc1bd5f786fb2a9612f710c9c2d964978025d34eb9fe25899"},
     {11000,"f674ec1545ec21172f7299bd79c7f80f70e02df12b896b5d18307d1cdee67f80"},
     {22000,"05f59eebe82c297beffa73abebca68d2bedeb40a13381d498e2355e9a1625127"},
     {33000,"0569528c3c146ed11bf6029818b90706314ffcd35ae4ecac9dbfb053a21910e7"},
     {34000,"0fc783c527e689de9c778a11d401953ffe345771d41caeb1fb8d3b00bbfb8c30"},
     {34100,"862f3b5b84daab70f895a138ff2d107123baacee3e273dfc3aeac3ed7f969869"},
     {34200,"1ba1c79f6ff1d7cd128b75293dd9779c6802f3b293aee44f2c7a60d525975d9c"},
     {34300,"9c63b1059b4d84055442874a3b8913598b04dfb36ea48049dd66227d10c250a0"},
     {34400,"30ac2f1f686aa6578b65bc739223691e8613e1d4037a2c74f26ae656c0abce66"},
     {34500,"e3585f18e09ab1bcd81f35d7f50573a28484e26412e302675a7a5eb488547835"},
     {34600,"a7b8bfd63a432123f35df50c526ed26853c87661644214e8859afe9666878e33"},
     {35000,"2f6b878dfd0c095254efc6824940a315daba73fd62e0156be6a7f99f4606b0fe"},
     {35500,"8195a8bde0963db1ef428e3239169ce8a3d723c7f5714600ed85b8360d1cf2bc"},
     {40000,"ad7b1a7cae0be44cbf04f7f010db601d38d8c9cd30b5f60408a778ce3ed16892"},
     {41000,"e37a7e38029e11f658cdd56a1cd26bb55e4cd673e94147825fa85d7c7564426d"},
     {41800,"f71d3ffe8189b3ec19d015c70d2fd50fd78b9cb660e0319290df1adb3ca7c688"},
     {42000,"cd12e710f5a1b8a01d19d4ccc76db57ac6ee017456c4c1778307fdda85126ea3"},
     {42500,"a099cf10fd105e17c77a8ffec66fc5f2f787b03d0de31a3acecc550ca7845a2a"},
     {43000,"8bb4bf8dceeeb7aafdee98f1949c0dc7ae030317b85f0d7956087ace64f6b18b"},
     {43500,"c9f85cd6b5a622590f7b9c8ab20f914bb70b59bdbc48db08b0dcaccf646c33ef"},
     {44000,"aa8945c0d87050ff10c5deae2f6fc146efc9847e839096a556c7c1704c082c19"},
     {44500,"eb95fe79af5aa6b6ecf73117aeeb6fbaf217110da9ba51c12af389298f25f653"},
     {45000,"f22c56ef6174507f04f44d9b0206268689454ceb1b41e775964d447ae45d46c4"},
     {45500,"4635aa86897b649e0409f8bb7a23649f3e63578c5a2a1225b3d1e9df26dfb553"},
    {50000,"4cd1655c21bdcc724b77717602e1d2f5a8af34061c94b34dba720c6875e9a7cf"},
    {55000,"d96d63c2eec6bdb462052ff4d4140c4963ef2f0016571e11a3beb6d4c99ca38c"},
    {60000,"44001d75be46fd97bccdb44fbf517b862c3abcfa22bf8f15eadd2c21f1b9e6e9"},
    {65000,"b5cdfa0fb1a20c4d41c562597961f3127aed9508c614e5a86fb68342be976f1e"},
    {66000,"2868d7eefe1d1f53f5d1c00bd0e490b9e4910db352ddc0fbfbb7b94f693ff15a"},
    {66500,"60720ce3ede3dfb549b1611e9c28b259773f3c57bd28cebca6082a785d89a600"},
    };

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



