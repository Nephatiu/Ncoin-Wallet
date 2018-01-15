cmake_minimum_required(VERSION 2.8)

include(CryptoNoteWallet.cmake)

project(${CN_PROJECT_NAME})

execute_process(COMMAND git log -1 --pretty=format:%h
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
OUTPUT_VARIABLE GIT_REVISION)

set(CRYPTONOTE_LIB Ncore)

include_directories(${CMAKE_BINARY_DIR}
    src
    Ncore/external
    Ncore/include
    Ncore/src)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
  set(Boost_USE_STATIC_RUNTIME OFF)
else(WIN32)
  set(Boost_USE_STATIC_RUNTIME ON)
endif(WIN32)

find_package(Boost 1.55 REQUIRED COMPONENTS date_time filesystem program_options regex serialization system thread chrono)
if ((${Boost_MAJOR_VERSION} EQUAL 1) AND (${Boost_MINOR_VERSION} EQUAL 54))
	message(SEND_ERROR "Boost version 1.54 is unsupported, more details are available here http://goo.gl/RrCFmA")
endif ()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(VERSION "")
configure_file("Ncore/src/version.h.in" "version.h")
configure_file("src/CryptoNoteWalletConfig.h.in" "CryptoNoteWalletConfig.h")

add_definitions(-DGIT_REVISION=\"${GIT_REVISION}\")

set(CMAKE_AUTOMOC ON)

set(CRYPTONOTE_SOURCES
  Ncore/external/miniupnpc/connecthostport.c
  Ncore/external/miniupnpc/igd_desc_parse.c
  Ncore/external/miniupnpc/minisoap.c
  Ncore/external/miniupnpc/miniupnpc.c
  Ncore/external/miniupnpc/miniwget.c
  Ncore/external/miniupnpc/minixml.c
  Ncore/external/miniupnpc/portlistingparse.c
  Ncore/external/miniupnpc/receivedata.c
  Ncore/external/miniupnpc/upnpcommands.c
  Ncore/external/miniupnpc/upnpreplyparse.c
  Ncore/src/Common/Base58.cpp
  Ncore/src/Common/CommandLine.cpp
  Ncore/src/Common/Util.cpp
  Ncore/src/Common/StringTools.cpp
  Ncore/src/Common/JsonValue.cpp
  Ncore/src/Common/ConsoleTools.cpp
  Ncore/src/Common/MemoryInputStream.cpp
  Ncore/src/Common/PathTools.cpp
  Ncore/src/Common/StdInputStream.cpp
  Ncore/src/Common/StdOutputStream.cpp
  Ncore/src/Common/StreamTools.cpp
  Ncore/src/Common/StringOutputStream.cpp
  Ncore/src/Common/StringView.cpp
  Ncore/src/Common/VectorOutputStream.cpp
  Ncore/src/crypto/blake256.c
  Ncore/src/crypto/chacha8.c
  Ncore/src/crypto/crypto-ops-data.c
  Ncore/src/crypto/crypto-ops.c
  Ncore/src/crypto/crypto.cpp
  Ncore/src/crypto/groestl.c
  Ncore/src/crypto/hash-extra-blake.c
  Ncore/src/crypto/hash-extra-groestl.c
  Ncore/src/crypto/hash-extra-jh.c
  Ncore/src/crypto/hash-extra-skein.c
  Ncore/src/crypto/hash.c
  Ncore/src/crypto/jh.c
  Ncore/src/crypto/keccak.c
  Ncore/src/crypto/oaes_lib.c
  Ncore/src/crypto/random.c
  Ncore/src/crypto/skein.c
  Ncore/src/crypto/slow-hash.c
  Ncore/src/crypto/slow-hash.cpp
  Ncore/src/crypto/tree-hash.c
  Ncore/src/CryptoNoteCore/BlockchainIndices.cpp
  Ncore/src/CryptoNoteCore/BlockchainMessages.cpp
  Ncore/src/CryptoNoteCore/BlockIndex.cpp
  Ncore/src/CryptoNoteCore/CoreConfig.cpp
  Ncore/src/CryptoNoteCore/CryptoNoteBasic.cpp
  Ncore/src/CryptoNoteCore/CryptoNoteTools.cpp
  Ncore/src/CryptoNoteCore/Currency.cpp
  Ncore/src/CryptoNoteCore/MinerConfig.cpp
  Ncore/src/CryptoNoteCore/Transaction.cpp
  Ncore/src/CryptoNoteCore/Account.cpp
  Ncore/src/CryptoNoteCore/Blockchain.cpp
  Ncore/src/CryptoNoteCore/Checkpoints.cpp
  Ncore/src/CryptoNoteCore/CryptoNoteBasicImpl.cpp
  Ncore/src/CryptoNoteCore/Core.cpp
  Ncore/src/CryptoNoteCore/CryptoNoteFormatUtils.cpp
  Ncore/src/CryptoNoteCore/CryptoNoteSerialization.cpp
  Ncore/src/CryptoNoteCore/Difficulty.cpp
  Ncore/src/CryptoNoteCore/IBlock.cpp
  Ncore/src/CryptoNoteCore/Miner.cpp
  Ncore/src/CryptoNoteCore/TransactionExtra.cpp
  Ncore/src/CryptoNoteCore/TransactionPool.cpp
  Ncore/src/CryptoNoteCore/TransactionPrefixImpl.cpp
  Ncore/src/CryptoNoteCore/TransactionUtils.cpp
  Ncore/src/InProcessNode/InProcessNode.cpp
  Ncore/src/InProcessNode/InProcessNodeErrors.cpp
  Ncore/src/NodeRpcProxy/NodeErrors.cpp
  Ncore/src/NodeRpcProxy/NodeRpcProxy.cpp
  Ncore/src/P2p/NetNodeConfig.cpp
  Ncore/src/Serialization/BinaryInputStreamSerializer.cpp
  Ncore/src/Serialization/BinaryOutputStreamSerializer.cpp
  Ncore/src/Serialization/JsonInputValueSerializer.cpp
  Ncore/src/Serialization/JsonOutputStreamSerializer.cpp
  Ncore/src/Serialization/KVBinaryInputStreamSerializer.cpp
  Ncore/src/Serialization/KVBinaryOutputStreamSerializer.cpp
  Ncore/src/Serialization/SerializationOverloads.cpp
  Ncore/src/Transfers/BlockchainSynchronizer.cpp
  Ncore/src/Transfers/SynchronizationState.cpp
  Ncore/src/Transfers/TransfersConsumer.cpp
  Ncore/src/Transfers/TransfersContainer.cpp
  Ncore/src/Transfers/TransfersSubscription.cpp
  Ncore/src/Transfers/TransfersSynchronizer.cpp
  Ncore/src/Wallet/LegacyKeysImporter.cpp
  Ncore/src/Wallet/WalletAsyncContextCounter.cpp
  Ncore/src/Wallet/WalletErrors.cpp
  Ncore/src/WalletLegacy/KeysStorage.cpp
  Ncore/src/WalletLegacy/WalletLegacy.cpp
  Ncore/src/WalletLegacy/WalletHelper.cpp
  Ncore/src/WalletLegacy/WalletLegacySerializer.cpp
  Ncore/src/WalletLegacy/WalletLegacySerialization.cpp
  Ncore/src/WalletLegacy/WalletTransactionSender.cpp
  Ncore/src/WalletLegacy/WalletUnconfirmedTransactions.cpp
  Ncore/src/WalletLegacy/WalletUserTransactionsCache.cpp
  Ncore/src/System/ContextGroup.cpp
  Ncore/src/System/Event.cpp
  Ncore/src/System/EventLock.cpp
  Ncore/src/System/InterruptedException.cpp
  Ncore/src/System/Ipv4Address.cpp
  Ncore/src/System/TcpStream.cpp
  Ncore/src/HTTP/HttpRequest.cpp
  Ncore/src/HTTP/HttpParser.cpp
  Ncore/src/HTTP/HttpParserErrorCodes.cpp
  Ncore/src/HTTP/HttpResponse.cpp
  Ncore/src/Rpc/HttpClient.cpp
  Ncore/src/Rpc/JsonRpc.cpp
  Ncore/src/P2p/NetNode.cpp
  Ncore/src/P2p/LevinProtocol.cpp
  Ncore/src/P2p/NetNodeConfig.cpp
  Ncore/src/P2p/PeerListManager.cpp
  Ncore/src/CryptoNoteProtocol/CryptoNoteProtocolHandler.cpp
  Ncore/src/Logging/ILogger.cpp
  Ncore/src/Logging/LoggerGroup.cpp
  Ncore/src/Logging/CommonLogger.cpp
  Ncore/src/Logging/LoggerManager.cpp
  Ncore/src/Logging/FileLogger.cpp
  Ncore/src/Logging/StreamLogger.cpp
  Ncore/src/Logging/ConsoleLogger.cpp
  Ncore/src/Logging/LoggerMessage.cpp
  Ncore/src/Logging/LoggerRef.cpp
  Ncore/src/BlockchainExplorer/BlockchainExplorer.cpp
  Ncore/src/BlockchainExplorer/BlockchainExplorerDataBuilder.cpp
  Ncore/src/BlockchainExplorer/BlockchainExplorerErrors.cpp
)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE FORMS src/gui/ui/*.ui)

set(QRC src/resources.qrc)

qt5_wrap_ui(UIS ${FORMS})
qt5_add_resources(RCC ${QRC})


if (WIN32)
  if (NOT MSVC)
	message(FATAL_ERROR "Only MSVC is supported on this platform")
  endif ()
  add_definitions(/D_CRT_SECURE_NO_WARNINGS /D_WIN32_WINNT=0x0600 /DSTATICLIB)
  include_directories(Ncore/src/platform/msc)

  set(PLATFORM_DIR Windows)
  set(BUILD_PLATFORM WIN32)
  set(BUILD_RESOURCES src/cryptonotewallet.rc)
  set(QTMAIN Qt5::WinMain)

elseif (UNIX)
  set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} Ncore/external/miniupnpc/minissdpc.c)
  if (APPLE)
    enable_language(ASM)
    file(GLOB_RECURSE OBJC_SOURCES src/*.mm)
    set(SOURCES ${SOURCES} ${OBJC_SOURCES})
    set(PLATFORM_DIR OSX)
    set(MACOSX_BUNDLE_INFO_STRING "Cryptonote GUI wallet")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_NAME CryptonoteWallet)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "$${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")

    find_package(Qt5PrintSupport REQUIRED)

    include_directories(/usr/include/malloc)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11 -stdlib=libc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -maes -D_DARWIN_C_SOURCE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework CoreFoundation -framework Carbon -framework IOKit -L/usr/lib")

    set(MACOSX_BUNDLE_ICON_FILE cryptonote.icns)
    set(APPLICATION_ICON src/images/cryptonote.icns)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set(BUILD_PLATFORM MACOSX_BUNDLE)
    set(BUILD_RESOURCES ${APPLICATION_ICON})

    GET_TARGET_PROPERTY(QT_LIB_DIR "${Qt5Widgets_LIBRARIES}" LOCATION)
    GET_FILENAME_COMPONENT(QT_LIB_DIR "${QT_LIB_DIR}" PATH)
  else(APPLE)
    set(PLATFORM_DIR Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -std=c11")
  endif (APPLE)
endif ()

include_directories(Ncore/src/Platform/${PLATFORM_DIR})
file(GLOB PLATFORM_SOURCES Ncore/src/Platform/${PLATFORM_DIR}/System/*)
set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} ${PLATFORM_SOURCES})

add_library(${CRYPTONOTE_LIB} STATIC ${CRYPTONOTE_SOURCES})
set_target_properties(${CRYPTONOTE_LIB} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${CRYPTONOTE_LIB} ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} ${BUILD_PLATFORM} ${BUILD_RESOURCES} ${SOURCES} ${HEADERS} ${UIS} ${RCC})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QTMAIN} ${CRYPTONOTE_LIB})

if (APPLE)
  qt5_use_modules(${PROJECT_NAME} PrintSupport)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} -lpthread)
elseif (WIN32)
  target_link_libraries(${PROJECT_NAME} Imm32 Iphlpapi Winmm)
endif (APPLE)

qt5_use_modules(${PROJECT_NAME} Widgets Gui Network)
