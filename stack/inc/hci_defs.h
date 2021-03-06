/**
 * Definitions required by the HCI layer
 */
#pragma once

#include "hci_error.h"
#include "toy_ble.h"

typedef uint16_t HciOpcode;
#define HCI_OPCODE(ogf, ocf) (HciOpcode)((ocf | ogf << 10))

#define HCI_ADVERTISING_DATA_LEN 31

/**
 * HCI Packet Types
 */
typedef enum {
    kHciPacketTypeCommand   = 0x01,
    kHciPacketTypeAclData   = 0x02,
    kHciPacketTypeSyncData  = 0x03,
    kHciPacketTypeEventData = 0x04,
} HciPacketType;

/**
 * HCI Group Types (OGFs)
 */
typedef enum {
    kHciGroupLinkControl         = 0x01,
    kHciGroupLinkPolicy          = 0x02,
    kHciGroupControllerBaseband  = 0x03,
    kHciGroupInformationalParams = 0x04,
    kHciGroupStatusParams        = 0x05,
    kHciGroupTest                = 0x06,
    kHciGroupLeController        = 0x08,
    kHciGroupVendorSpecific      = 0x3F,
} HciGroup;

/**
 * Link Control Commands (OGF 0x01)
 * BT Spec: Vol 2, Part E, Section 7.1
 */
typedef enum {
    kHciCmdLinkControlInquiry                     = 0x01,
    kHciCmdLinkControlInquiryCancel               = 0x02,
    kHciCmdLinkControlPeriodicInquiryMode         = 0x03,
    kHciCmdLinkControlExitPeriodicInquiryMode     = 0x04,
    kHciCmdLinkControlCreateConnection            = 0x05,
    kHciCmdLinkControlDisconnect                  = 0x06,
    kHciCmdLinkControlAddSCOConnection            = 0x07,
    kHciCmdLinkControlAcceptConnectionRequest     = 0x09,
    kHciCmdLinkControlRejectConnectionRequest     = 0x0A,
    kHciCmdLinkControlLinkKeyRequestReply         = 0x0B,
    kHciCmdLinkControlLinkKeyRequestNegativeReply = 0x0C,
    kHciCmdLinkControlPINRequestReply             = 0x0D,
    kHciCmdLinkControlPINRequestNegativeReply     = 0x0E,
    kHciCmdLinkControlChangeConnectionPacketType  = 0x0F,
    kHciCmdLinkControlAuthenticationRequested     = 0x11,
    kHciCmdLinkControlSetConnectionEncryption     = 0x13,
    kHciCmdLinkControlChangeConnectionLinkKey     = 0x15,
    kHciCmdLinkControlMasterLinkKey               = 0x17,
    kHciCmdLinkControlRemoteNameRequest           = 0x19,
    kHciCmdLinkControlReadRemoteSupportedFeatures = 0x1B,
    kHciCmdLinkControlReadRemoteVersionInfo       = 0x1D,
    kHciCmdLinkControlReadClockOffset             = 0x1F,
} HciCmdLinkControl;

/**
 * Link Policy Commands (OGF 0x02)
 * BT Spec: Vol 2, Part E, Section 7.2
 */
typedef enum {
    kHciCmdLinkPolicyHoldMode      = 0x01,
    kHciCmdLinkPolicySniffMode     = 0x03,
    kHciCmdLinkPolicyExitSniffMode = 0x04,
    kHciCmdLinkPolicyParkMode      = 0x05,
    kHciCmdLinkPolicyExitParkMode  = 0x06,
    kHciCmdLinkPolicyQoSSetup      = 0x07,
    kHciCmdLinkPolicyRoleDiscovery = 0x09,
    kHciCmdLinkPolicySwitchRole    = 0x0B,
    kHciCmdLinkPolicyReadSettings  = 0x0C,
    kHciCmdLinkPolicyWriteSettings = 0x0D,
} HciCmdLinkPolicy;

/**
 * Controller and Baseband Commands (OGF 0x03)
 * BT Spec: Vol 2, Part E, Section 7.1
 */
typedef enum {
    kHciCmdControllerSetEventMask                   = 0x01,
    kHciCmdControllerReset                          = 0x03,
    kHciCmdControllerSetEventFilter                 = 0x05,
    kHciCmdControllerFlush                          = 0x08,
    kHciCmdControllerReadPINType                    = 0x09,
    kHciCmdControllerWritePINType                   = 0x0A,
    kHciCmdControllerCreateNewUnitKey               = 0x0B,
    kHciCmdControllerReadStoredLinkKey              = 0x0D,
    kHciCmdControllerWriteStoredLinkKey             = 0x11,
    kHciCmdControllerDeleteStoredLinkKey            = 0x12,
    kHciCmdControllerChangeLocalName                = 0x13,
    kHciCmdControllerReadLocalName                  = 0x14,
    kHciCmdControllerReadConnectionAcceptTimeout    = 0x15,
    kHciCmdControllerWriteConnectionAcceptTimeout   = 0x16,
    kHciCmdControllerReadPageTimeout                = 0x17,
    kHciCmdControllerWritePageTimeout               = 0x18,
    kHciCmdControllerReadScanEnable                 = 0x19,
    kHciCmdControllerWriteScanEnable                = 0x1A,
    kHciCmdControllerReadPageScanActivity           = 0x1B,
    kHciCmdControllerWritePageScanActivity          = 0x1C,
    kHciCmdControllerReadInquiryScanActivity        = 0x1D,
    kHciCmdControllerWriteInquiryScanActivity       = 0x1E,
    kHciCmdControllerReadAuthEnable                 = 0x1F,
    kHciCmdControllerWriteAuthEnable                = 0x20,
    kHciCmdControllerReadEncryptionMode             = 0x21,
    kHciCmdControllerWriteEncryptionMode            = 0x22,
    kHciCmdControllerReadClassOfDevice              = 0x23,
    kHciCmdControllerWriteClassOfDevice             = 0x24,
    kHciCmdControllerReadVoiceSetting               = 0x25,
    kHciCmdControllerWriteVoiceSetting              = 0x26,
    kHciCmdControllerReadAutoFlushTimeout           = 0x27,
    kHciCmdControllerWriteAutoFlushTimeout          = 0x28,
    kHciCmdControllerReadNumBroadcastRetrans        = 0x29,
    kHciCmdControllerWriteNumBroadcastRetrans       = 0x2A,
    kHciCmdControllerReadHoldModeActivity           = 0x2B,
    kHciCmdControllerWriteHoldModeActivity          = 0x2C,
    kHciCmdControllerReadTransmitPowerLevel         = 0x2D,
    kHciCmdControllerReadSCOFlowControlEnable       = 0x2E,
    kHciCmdControllerWriteSCOFlowControlEnable      = 0x2F,
    kHciCmdControllerSetControllerToHostFlowControl = 0x31,
    kHciCmdControllerHostBufferSize                 = 0x33,
    kHciCmdControllerHostNumCompletedPackets        = 0x35,
    kHciCmdControllerReadLinkSupervisionTimeout     = 0x36,
    kHciCmdControllerWriteLinkSupervisionTimeout    = 0x37,
    kHciCmdControllerReadNumSupportedIAC            = 0x38,
    kHciCmdControllerReadCurrentIAC_LAP             = 0x39,
    kHciCmdControllerWriteCurrentIAC_LAP            = 0x3A,
    kHciCmdControllerReadPageScanPeriodMode         = 0x3B,
    kHciCmdControllerWritePageScanPeriodMode        = 0x3C,
    kHciCmdControllerReadPageScanMode               = 0x3D,
    kHciCmdControllerWritePageScanMode              = 0x3E,
} HciCmdControllerBaseband;

/**
 * LE Controller Commands (OGF 0x08)
 * BT Spec: Vol 2, Part E, Section 7.8
 */
typedef enum {
    kHciCmdLeSetEventMask                          = 0x01,
    kHciCmdLeReadBufferSize                        = 0x02,
    kHciCmdLeReadLocalSupportedFeatures            = 0x03,
    kHciCmdLeSetRandomAddr                         = 0x05,
    kHciCmdLeSetAdvertisingParams                  = 0x06,
    kHciCmdLeReadAdvertisingChannelTxPower         = 0x07,
    kHciCmdLeSetAdvertisingData                    = 0x08,
    kHciCmdLeSetScanResponseData                   = 0x09,
    kHciCmdLeSetAdvertiseEnable                    = 0x0A,
    kHciCmdLeSetScanParams                         = 0x0B,
    kHciCmdLeSetScanEnable                         = 0x0C,
    kHciCmdLeCreateConnection                      = 0x0D,
    kHciCmdLeCreateConnectionCancel                = 0x0E,
    kHciCmdLeReadWhiteListSize                     = 0x0F,
    kHciCmdLeClearWhiteList                        = 0x10,
    kHciCmdLeAddDeviceToWhiteList                  = 0x11,
    kHciCmdLeRemoveDeviceFromWhiteList             = 0x12,
    kHciCmdLeConnectionUpdate                      = 0x13,
    kHciCmdLeSetHostChannelClassification          = 0x14,
    kHciCmdLeReadChannelMap                        = 0x15,
    kHciCmdLeReadRemoteUsedFeatures                = 0x16,
    kHciCmdLeEncrypt                               = 0x17,
    kHciCmdLeRand                                  = 0x18,
    kHciCmdLeStartEncryption                       = 0x19,
    kHciCmdLeLongTermKeyRequestReply               = 0x1A,
    kHciCmdLeLongTermKeyRequestNegativeReply       = 0x1B,
    kHciCmdLeReadSupportedStates                   = 0x1C,
    kHciCmdLeReceiverTest                          = 0x1D,
    kHciCmdLeTransmitterTest                       = 0x1E,
    kHciCmdLeTestEnd                               = 0x1F,
    kHciCmdLeRemoteConnectionParamReqReply         = 0x20,
    kHciCmdLeRemoteConnectionParamReqNegativeReply = 0x21,
    kHciCmdLeSetDataLength                         = 0x22,
    kHciCmdLeReadSuggestedDefaultDataLength        = 0x23,
    kHciCmdLeWriteSuggestedDefaultDataLength       = 0x24,
    kHciCmdLeReadLocalP256PublicKey                = 0x25,
    kHciCmdLeGenerateDHKey                         = 0x26,
    kHciCmdLeAddDeviceToResolvingList              = 0x27,
    kHciCmdLeRemoveDeviceFromResolvingList         = 0x28,
    kHciCmdLeClearResolvingList                    = 0x29,
    kHciCmdLeReadResolvingListSize                 = 0x2A,
    kHciCmdLeReadPeerResolvableAddr                = 0x2B,
    kHciCmdLeReadLocalResolvableAddr               = 0x2C,
    kHciCmdLeSetAddrResolutionEnable               = 0x2D,
    kHciCmdLeSetResolvablePrivateAddrTimeout       = 0x2E,
    kHciCmdLeReadMaximumDataLength                 = 0x2F,
} HciCmdLeController;

/**
 * HCI ACL Packet Boundary Flags
 */
typedef enum {
    kHciAclPbFlagFirstNonFlushable  = 0x0,
    kHciAclPbFlagContinuingFragment = 0x1,
    kHciAclPbFlagFirstFlushable     = 0x2,
    kHciAclPbFlagCompleteL2capPdu   = 0x3,
} HciAclPacketBoundaryFlag;

#pragma pack(1)
typedef struct {
    uint8_t type;
    uint8_t data[];
} HciPkt;
#pragma pack()

#pragma pack(1)
typedef struct {
    uint16_t opcode;
    uint8_t param_len;
} HciCmdHdr;
#pragma pack()

// @TODO might not want to use bitfields here
#pragma pack(1)
typedef struct {
    uint16_t conn_handle : 12;
    uint16_t pkt_boundary_flag : 2;
    uint16_t broadcast_flag : 2;
    uint16_t data_len;
} HciAclDataHdr;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciAclDataHdr hdr;
    uint8_t data[];
} HciAclDataPkt;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint8_t params[];
} HciCmd;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
} HciCmdReset;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint16_t adv_interval_min;
    uint16_t adv_interval_max;
    uint8_t adv_type;
    uint8_t own_addr_type;
    uint8_t peer_addr_type;
    uint8_t peer_addr[BD_ADDR_LEN];
    uint8_t adv_chan_map;
    uint8_t adv_filter_policy;
} HciCmdSetAdvertisingParams;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint8_t adv_data_len;
    uint8_t adv_data[HCI_ADVERTISING_DATA_LEN];
} HciCmdSetAdvertisingData;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint8_t enable;
} HciCmdSetAdvertiseEnable;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint8_t le_scan_type;
    uint16_t le_scan_interval;
    uint16_t le_scan_window;
    uint8_t own_address_type;
    uint8_t scanning_filter_policy;
} HciCmdSetScanParams;
#pragma pack()

#pragma pack(1)
typedef struct {
    HciCmdHdr hdr;
    uint8_t enable;
    uint8_t filter_duplicates;
} HciCmdSetScanEnable;
#pragma pack()

#define HCI_MAX_PARAM_LEN (UINT8_MAX)
#define HCI_MAX_CMD_LEN (HCI_MAX_PARAM_LEN + sizeof(HciCmdHdr))
