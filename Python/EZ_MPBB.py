import sys, os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from PyICe_driver.MPBB import MPBB
from PyICe import lab_core
from PyICe.lab_utils.banners import print_banner

print_banner("", "Please enter the COM port number for your MPBB.", "", "It can be obtained from the Windows Device Manager.", "")
comport = input("Enter COM port number, COM")
channel_master = lab_core.channel_master()
MPBB_board = MPBB(channel_master=channel_master, comport=f"COM{comport}", verbose=False)
channel_master.add(MPBB_board)
channel_master.write("MPBB_enable", "OFF") # Board is stateful
channel_master.write("MPBB_wd_svc_time", 16000)
channel_master.write("MPBB_wd_svc_enable", True)
channel_master.write("MPBB_wddis", True)
channel_master.gui()