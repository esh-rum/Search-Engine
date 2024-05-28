//#pragma once
//
//using namespace System;
//using namespace System::Collections::Generic;
//using namespace System::Text;
//using namespace System::Threading::Tasks;
//using namespace System::ComponentModel;
//using namespace System::Windows::Forms;
//using namespace System::Data;
//using namespace System::Drawing;
//using namespace System::Runtime::InteropServices;
//
//namespace WindowsFormsApp10 {
//	ref class mdiProperties {
//		[DllImport("user32.dll")]
//			static int GetWindowLong(IntPtr hWnd, int nIndex);
//		[DllImport("user32.dll")]
//			static int SetWindowLong(IntPtr hWnd, int nIndex, int dwNewLong	);
//		[DllImport("user32.dll")]
//			static int SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags);
//
//		static const int GWL_EXSTYLE = -20;
//		static const int WS_EX_CLIENTEDGE = 0x200;
//		static const unsigned int SWP_NOSIZE = 0x0001;
//		static const unsigned int SWP_NOMOVE = 0x0002;
//		static const unsigned int SWP_NOZORDER = 0x0004;
//		static const unsigned int SWO_NOACTIVATE = 0x0010;
//		static const unsigned int SWP_FRAMECHANGED = 0x0020;
//		static const unsigned int SWO_NOOWNERZORDER = 0x0200;
//
//	public:
//
//
//		static bool SetBevel(Form^ form, bool show) {
//			for each (Control ^ c in form->Controls) {
//				MdiClient^ client = dynamic_cast<MdiClient^>(c);
//				if (client != nullptr) {
//					int windowLong = GetWindowLong(c->Handle, GWL_EXSTYLE);
//					if (show) {
//						windowLong |= WS_EX_CLIENTEDGE;
//					}
//					else {
//						windowLong &= ~WS_EX_CLIENTEDGE; // Use bitwise AND with NOT to remove the style
//					}
//
//					SetWindowLong(c->Handle, GWL_EXSTYLE, windowLong);
//					SetWindowPos(client->Handle, IntPtr::Zero, 0, 0, 0, 0,
//						SWO_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
//					return true;
//				}
//				return false;
//			}
//		}
//	};
//}