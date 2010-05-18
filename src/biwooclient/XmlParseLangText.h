/*
    Biwoo is an enterprise communication software base on CGCP.
    Copyright (C) 2009-2010  Akee Yang <akee.yang@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// XmlParseLangText.h file here
#ifndef __XmlParseLangText_h__
#define __XmlParseLangText_h__
#pragma warning(disable:4819)

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

class XmlParseLangText
{
public:
	XmlParseLangText(void)
		: m_menuFile("")
		, m_menuChangeAccText(""), m_menuChangeAccHelp(""), m_menuChangeAccQuestion("")
		, m_menuExitText(""), m_menuExitHelp(""), m_menuExitQuestion("")
		, m_menuHelp(""), m_menuAboutText(""), m_menuAboutHelp("")
		, m_menuHideText(""), m_menuHideHelp(""), m_menuRestoreText(""), m_menuRestoreHelp("")
		, m_dlgLoginTitle(""), m_dlgLoginAccountText(""), m_dlgLoginAccountHelp(""), m_dlgLoginPasswordText(""), m_dlgLoginPasswordHelp("")
		, m_dlgAddUserTitle(""), m_dlgStaticChooseFrom(""), m_dlgStaticChooseTo("")
		, m_btnLoginText(""), m_btnLoginHelp("")
		, m_btnCancelText(""), m_btnCancelHelp("")
		, m_btnMyCompanyText("")//, m_btnMyCompanyHelp("")
		, m_btnMyDepartmentText("")//, m_btnMyDepartmentHelp("")
		, m_btnSendMsgText(""), m_btnSendMsgHelp(""), m_btnSendFileText(""), m_btnSendFileHelp(""), m_btnVideoCallText(""), m_btnVideoCallHelp("")
		, m_btnReleaseCallText(""), m_btnReleaseCallHelp(""), m_btnAcceptCallText(""), m_btnAcceptCallHelp("")
		, m_btnAcceptFile(""), m_btnSaveFileAs(""), m_btnRejectFile(""), m_btnCancelFile(""), m_btnOpenFile(""), m_btnOpenFolder("")
		, m_btnAddUserText(""), m_btnAddUserHelp("")
		, m_btnQuitDialogText(""), m_btnQuitDialogHelp("")
		, m_checkSavePassword(""), m_checkAutoLogin("")
		, m_textWelcome("")
		, m_textAllContacts(""), m_textConversations("")
		, m_textSearchTip("")
		, m_textLoginTimeout(""), m_textAccOrPwdError(""), m_textConnectError(""), m_textSystemError("")
		, m_textSelectUserTip(""), m_textOfflineSendfileTip(""), m_textOfflineVideoCallTip(""), m_textLoginAnotherPlaceTip(""), m_textServerQuitTip("")
		, m_textHadUnreadMsgTip("")
		, m_textSendFileto(""), m_textSaveFileto(""), m_textAllFiles("")
		, m_textFileCanceled(""), m_textFileRejected(""), m_textWaitForReceive(""), m_textAcceptFile(""), m_textFileArrived(""), m_textFileSent("")
		, m_textOnlineState(""), m_textOfflineState(""), m_textAwayState("")
		, m_textCompanyType(""), m_textCoGroupType(""), m_textGroupType("")

	{}
	~XmlParseLangText(void)
	{}

public:
	void load(const std::string & filename)
	{
		// 建立空的property tree对象
		using boost::property_tree::ptree;
		ptree pt;

		// 把XML文件载入到property tree里. 如果出错    // (无法打开文件,解析错误), 抛出一个异常.
		//std::locale loc("chs");
		//read_xml(filename, pt, 0, loc);
		read_xml(filename, pt);

		// 如果键里有小数点,我们可以在get方法中指定其它分隔符
		m_menuFile = pt.get("root.menu.file", _T("file"));
		m_menuChangeAccText = pt.get("root.menu.changeaccount.text", _T("changeaccount"));
		m_menuChangeAccHelp = pt.get("root.menu.changeaccount.help", _T("changeaccount"));
		m_menuChangeAccQuestion = pt.get("root.menu.changeaccount.question", _T("changeaccount question"));
		m_menuExitText = pt.get("root.menu.exit.text", _T("exit"));
		m_menuExitHelp = pt.get("root.menu.exit.help", _T("exit"));
		m_menuExitQuestion = pt.get("root.menu.exit.question", _T("exit question"));
		m_menuHelp = pt.get("root.menu.help", _T("help"));
		m_menuAboutText = pt.get("root.menu.about.text", _T("about"));
		m_menuAboutHelp = pt.get("root.menu.about.help", _T("about"));
		//m_nCgcpRank = pt.get("root.cgcp.rank", 0);
		m_menuHideText = pt.get("root.menu.hide", _T("hide"));
		m_menuHideHelp = pt.get("root.menu.hide.help", _T("hide"));
		m_menuRestoreText = pt.get("root.menu.restore", _T("restore"));
		m_menuRestoreHelp = pt.get("root.menu.restore.help", _T("restore"));

		m_dlgLoginTitle = pt.get("root.dialog.login.title", _T("login title"));
		m_dlgLoginAccountText = pt.get("root.dialog.login.account", _T("login account"));
		m_dlgLoginAccountHelp = pt.get("root.dialog.login.account.help", _T("login account"));
		m_dlgLoginPasswordText = pt.get("root.dialog.login.password", _T("login password"));
		m_dlgLoginPasswordHelp = pt.get("root.dialog.login.password.help", _T("login password"));

		m_dlgAddUserTitle = pt.get("root.dialog.adduser.title", _T("adduser title"));
		m_dlgStaticChooseFrom = pt.get("root.dialog.adduser.stachoosefrom", _T("stachoosefrom"));
		m_dlgStaticChooseTo = pt.get("root.dialog.adduser.stachooseto", _T("stachooseto"));

		m_btnLoginText = pt.get("root.button.login", _T("login"));
		m_btnLoginHelp = pt.get("root.button.login.help", _T("login"));
		m_btnCancelText = pt.get("root.button.cancel", _T("cancel"));
		m_btnCancelHelp = pt.get("root.button.cancel.help", _T("cancel"));
		m_btnMyCompanyText = pt.get("root.button.mycompany", _T("my company"));
		//m_btnMyCompanyHelp = pt.get("root.button.mycompany.help", _T("my company"));
		m_btnMyDepartmentText = pt.get("root.button.mydepartment", _T("my department"));
		//m_btnMyDepartmentHelp = pt.get("root.button.mydepartment.help", _T("my department"));

		m_btnSendMsgText = pt.get("root.button.sendmsg", _T("send msg"));
		m_btnSendMsgHelp = pt.get("root.button.sendmsg.help", _T("send msg"));
		m_btnSendFileText = pt.get("root.button.sendfile", _T("send file"));
		m_btnSendFileHelp = pt.get("root.button.sendfile.help", _T("send file"));
		m_btnVideoCallText = pt.get("root.button.videocall", _T("video call"));
		m_btnVideoCallHelp = pt.get("root.button.videocall.help", _T("video call"));
		m_btnReleaseCallText = pt.get("root.button.releasecall", _T("release call"));
		m_btnReleaseCallHelp = pt.get("root.button.releasecall.help", _T("release call"));
		m_btnAcceptCallText = pt.get("root.button.acceptcall", _T("accept call"));
		m_btnAcceptCallHelp = pt.get("root.button.acceptcall.help", _T("accept call"));
		m_btnAddUserText = pt.get("root.button.adduser", _T("add user"));
		m_btnAddUserHelp = pt.get("root.button.adduser.help", _T("add user"));
		m_btnQuitDialogText = pt.get("root.button.quitdialog", _T("quit dialog"));
		m_btnQuitDialogHelp = pt.get("root.button.quitdialog.help", _T("quit dialog"));

		m_btnAcceptFile = pt.get("root.button.acceptfile", _T("accept file"));
		m_btnSaveFileAs = pt.get("root.button.savefileas", _T("save file as"));
		m_btnRejectFile = pt.get("root.button.rejectfile", _T("reject file"));
		m_btnCancelFile = pt.get("root.button.cancelfile", _T("cancel file"));
		m_btnOpenFile = pt.get("root.button.openfile", _T("open file"));
		m_btnOpenFolder = pt.get("root.button.openfolder", _T("open folder"));

		m_checkSavePassword = pt.get("root.check.savepassword", _T("save password"));
		m_checkAutoLogin = pt.get("root.check.autologin", _T("auto login"));

		m_textWelcome = pt.get("root.text.welcome", _T("welcome"));
		m_textAllContacts = pt.get("root.text.allcontacts", _T("allcontacts"));
		m_textConversations = pt.get("root.text.conversations", _T("conversations"));
		m_textSearchTip = pt.get("root.text.searchtip", _T("search contacts"));

		m_textLoginTimeout = pt.get("root.text.logintimeout", _T("login timeout error"));
		m_textAccOrPwdError = pt.get("root.text.accorpwderror", _T("account or password error"));
		m_textConnectError = pt.get("root.text.connecterror", _T("connect error"));
		m_textSystemError = pt.get("root.text.systemerror", _T("system error"));

		m_textSelectUserTip = pt.get("root.text.selectusertip", _T("select user tip"));
		m_textOfflineSendfileTip = pt.get("root.text.offlinesendfiletip", _T("offline sendfile tip"));
		m_textOfflineVideoCallTip = pt.get("root.text.offlinevideocalltip", _T("offline VideoCall tip"));
		m_textLoginAnotherPlaceTip = pt.get("root.text.loginanotherplacetip", _T("login another place tip"));
		m_textServerQuitTip = pt.get("root.text.serverquittip", _T("server quit tip"));
		m_textHadUnreadMsgTip = pt.get("root.text.unreadmsgtip", _T("rnuead msg tip"));

		m_textSendFileto = pt.get("root.text.sendfileto", _T("sendfileto"));
		m_textSaveFileto = pt.get("root.text.savefileto", _T("savefileto"));
		m_textAllFiles = pt.get("root.text.allfiles", _T("allfiles"));
		m_textFileCanceled = pt.get("root.text.filecanceled", _T("file canceled"));
		m_textFileRejected = pt.get("root.text.filerejected", _T("file rejected"));
		m_textWaitForReceive = pt.get("root.text.waitforreceive", _T("wait for receive"));
		m_textAcceptFile = pt.get("root.text.acceptfile", _T("accept file"));
		m_textFileArrived = pt.get("root.text.filearrived", _T("file arrived"));
		m_textFileSent = pt.get("root.text.filesent", _T("file sent"));

		m_textOnlineState = pt.get("root.text.onlinestate", _T("online"));
		m_textOfflineState = pt.get("root.text.offlinestate", _T("offline"));
		m_textAwayState = pt.get("root.text.awaystate", _T("away"));
		m_textCompanyType = pt.get("root.text.companytype", _T("company"));
		m_textCoGroupType = pt.get("root.text.cogrouptype", _T("department"));
		m_textGroupType = pt.get("root.text.grouptype", _T("group"));

	}

	const std::string & menuFile(void) const {return m_menuFile;}
	const std::string & menuChangeAccText(void) const {return m_menuChangeAccText;}
	const std::string & menuChangeAccHelp(void) const {return m_menuChangeAccHelp;}
	const std::string & menuChangeAccQuestion(void) const {return m_menuChangeAccQuestion;}
	const std::string & menuExitText(void) const {return m_menuExitText;}
	const std::string & menuExitHelp(void) const {return m_menuExitHelp;}
	const std::string & menuExitQuestion(void) const {return m_menuExitQuestion;}
	const std::string & menuHelp(void) const {return m_menuHelp;}
	const std::string & menuAboutText(void) const {return m_menuAboutText;}
	const std::string & menuAboutHelp(void) const {return m_menuAboutHelp;}

	const std::string & menuHideText(void) const {return m_menuHideText;}
	const std::string & menuHideHelp(void) const {return m_menuHideHelp;}
	const std::string & menuRestoreText(void) const {return m_menuRestoreText;}
	const std::string & menuRestoreHelp(void) const {return m_menuRestoreHelp;}

	const std::string & dlgLoginTitle(void) const {return m_dlgLoginTitle;}
	const std::string & dlgLoginAccountText(void) const {return m_dlgLoginAccountText;}
	const std::string & dlgLoginAccountHelp(void) const {return m_dlgLoginAccountHelp;}
	const std::string & dlgLoginPasswordText(void) const {return m_dlgLoginPasswordText;}
	const std::string & dlgLoginPasswordHelp(void) const {return m_dlgLoginPasswordHelp;}

	const std::string & dlgAddUserTitle(void) const {return m_dlgAddUserTitle;}
	const std::string & dlgStaticChooseFrom(void) const {return m_dlgStaticChooseFrom;}
	const std::string & dlgStaticChooseTo(void) const {return m_dlgStaticChooseTo;}

	const std::string & btnLoginText(void) const {return m_btnLoginText;}
	const std::string & btnLoginHelp(void) const {return m_btnLoginHelp;}
	const std::string & btnCancelText(void) const {return m_btnCancelText;}
	const std::string & btnCancelHelp(void) const {return m_btnCancelHelp;}
	const std::string & btnMyCompanyText(void) const {return m_btnMyCompanyText;}
	//const std::string & btnMyCompanyHelp(void) const {return m_btnMyCompanyHelp;}
	const std::string & btnMyDepartmentText(void) const {return m_btnMyDepartmentText;}
	//const std::string & btnMyDepartmentHelp(void) const {return m_btnMyDepartmentHelp;}

	const std::string & btnSendMsgText(void) const {return m_btnSendMsgText;}
	const std::string & btnSendMsgHelp(void) const {return m_btnSendMsgHelp;}
	const std::string & btnSendFileText(void) const {return m_btnSendFileText;}
	const std::string & btnSendFileHelp(void) const {return m_btnSendFileHelp;}
	const std::string & btnVideoCallText(void) const {return m_btnVideoCallText;}
	const std::string & btnVideoCallHelp(void) const {return m_btnVideoCallHelp;}
	const std::string & btnReleaseCallText(void) const {return m_btnReleaseCallText;}
	const std::string & btnReleaseCallHelp(void) const {return m_btnReleaseCallHelp;}
	const std::string & btnAcceptCallText(void) const {return m_btnAcceptCallText;}
	const std::string & btnAcceptCallHelp(void) const {return m_btnAcceptCallHelp;}
	const std::string & btnAddUserText(void) const {return m_btnAddUserText;}
	const std::string & btnAddUserHelp(void) const {return m_btnAddUserHelp;}
	const std::string & btnQuitDialogText(void) const {return m_btnQuitDialogText;}
	const std::string & btnQuitDialogHelp(void) const {return m_btnQuitDialogHelp;}

	const std::string & btnAcceptFile(void) const {return m_btnAcceptFile;}
	const std::string & btnSaveFileAs(void) const {return m_btnSaveFileAs;}
	const std::string & btnRejectFile(void) const {return m_btnRejectFile;}
	const std::string & btnCancelFile(void) const {return m_btnCancelFile;}
	const std::string & btnOpenFile(void) const {return m_btnOpenFile;}
	const std::string & btnOpenFolder(void) const {return m_btnOpenFolder;}

	const std::string & checkSavePassword(void) const {return m_checkSavePassword;}
	const std::string & checkAutoLogin(void) const {return m_checkAutoLogin;}

	const std::string & textWelcome(void) const {return m_textWelcome;}
	const std::string & textAllContacts(void) const {return m_textAllContacts;}
	const std::string & textConversations(void) const {return m_textConversations;}
	const std::string & textSearchTip(void) const {return m_textSearchTip;}

	const std::string & textLoginTimeout(void) const {return m_textLoginTimeout;}
	const std::string & textAccOrPwdError(void) const {return m_textAccOrPwdError;}
	const std::string & textConnectError(void) const {return m_textConnectError;}
	const std::string & textSystemError(void) const {return m_textSystemError;}

	const std::string & textSelectUserTip(void) const {return m_textSelectUserTip;}
	const std::string & textOfflineSendfileTip(void) const {return m_textOfflineSendfileTip;}
	const std::string & textOfflineVideoCallTip(void) const {return m_textOfflineVideoCallTip;}
	const std::string & textLoginAnotherPlaceTip(void) const {return m_textLoginAnotherPlaceTip;}
	const std::string & textServerQuitTip(void) const {return m_textServerQuitTip;}
	const std::string & textHadUnreadMsgTip(void) const {return m_textHadUnreadMsgTip;}

	const std::string & textSendFileto(void) const {return m_textSendFileto;}
	const std::string & textSaveFileto(void) const {return m_textSaveFileto;}
	const std::string & textAllFiles(void) const {return m_textAllFiles;}
	const std::string & textFileCanceled(void) const {return m_textFileCanceled;}
	const std::string & textFileRejected(void) const {return m_textFileRejected;}
	const std::string & textWaitForReceive(void) const {return m_textWaitForReceive;}
	const std::string & textAcceptFile(void) const {return m_textAcceptFile;}
	const std::string & textFileArrived(void) const {return m_textFileArrived;}
	const std::string & textFileSent(void) const {return m_textFileSent;}

	const std::string & textOnlineState(void) const {return m_textOnlineState;}
	const std::string & textOfflineState(void) const {return m_textOfflineState;}
	const std::string & textAwayState(void) const {return m_textAwayState;}
	const std::string & textCompanyType(void) const {return m_textCompanyType;}
	const std::string & textCoGroupType(void) const {return m_textCoGroupType;}
	const std::string & textGroupType(void) const {return m_textGroupType;}

private:
	// Menu
	std::string		m_menuFile;
	std::string		m_menuChangeAccText;
	std::string		m_menuChangeAccHelp;
	std::string		m_menuChangeAccQuestion;
	std::string		m_menuExitText;
	std::string		m_menuExitHelp;
	std::string		m_menuExitQuestion;
	std::string		m_menuHelp;
	std::string		m_menuAboutText;
	std::string		m_menuAboutHelp;
	std::string		m_menuHideText;
	std::string		m_menuHideHelp;
	std::string		m_menuRestoreText;
	std::string		m_menuRestoreHelp;

	// Dialog
	std::string		m_dlgLoginTitle;
	std::string		m_dlgLoginAccountText;
	std::string		m_dlgLoginAccountHelp;
	std::string		m_dlgLoginPasswordText;
	std::string		m_dlgLoginPasswordHelp;

	std::string		m_dlgAddUserTitle;
	std::string		m_dlgStaticChooseFrom;
	std::string		m_dlgStaticChooseTo;

	// Button
	std::string		m_btnLoginText;
	std::string		m_btnLoginHelp;
	std::string		m_btnCancelText;
	std::string		m_btnCancelHelp;
	std::string		m_btnMyCompanyText;
	//std::string		m_btnMyCompanyHelp;
	std::string		m_btnMyDepartmentText;
	//std::string		m_btnMyDepartmentHelp;

	std::string		m_btnSendMsgText;
	std::string		m_btnSendMsgHelp;
	std::string		m_btnSendFileText;
	std::string		m_btnSendFileHelp;
	std::string		m_btnVideoCallText;
	std::string		m_btnVideoCallHelp;
	std::string		m_btnReleaseCallText;
	std::string		m_btnReleaseCallHelp;
	std::string		m_btnAcceptCallText;
	std::string		m_btnAcceptCallHelp;
	std::string		m_btnAddUserText;
	std::string		m_btnAddUserHelp;
	std::string		m_btnQuitDialogText;
	std::string		m_btnQuitDialogHelp;

	std::string		m_btnAcceptFile;
	std::string		m_btnSaveFileAs;
	std::string		m_btnRejectFile;
	std::string		m_btnCancelFile;
	std::string		m_btnOpenFile;
	std::string		m_btnOpenFolder;

	std::string		m_checkSavePassword;
	std::string		m_checkAutoLogin;

	// Text
	std::string		m_textWelcome;
	std::string		m_textAllContacts;
	std::string		m_textConversations;

	std::string		m_textSearchTip;

	std::string		m_textLoginTimeout;
	std::string		m_textAccOrPwdError;
	std::string		m_textConnectError;
	std::string		m_textSystemError;

	std::string		m_textSelectUserTip;
	std::string		m_textOfflineSendfileTip;
	std::string		m_textOfflineVideoCallTip;
	std::string		m_textLoginAnotherPlaceTip;
	std::string		m_textServerQuitTip;
	std::string		m_textHadUnreadMsgTip;

	std::string		m_textSendFileto;
	std::string		m_textSaveFileto;
	std::string		m_textAllFiles;
	std::string		m_textFileCanceled;
	std::string		m_textFileRejected;
	std::string		m_textWaitForReceive;
	std::string		m_textAcceptFile;
	std::string		m_textFileArrived;
	std::string		m_textFileSent;

	std::string		m_textOnlineState;
	std::string		m_textOfflineState;
	std::string		m_textAwayState;
	std::string		m_textCompanyType;
	std::string		m_textCoGroupType;
	std::string		m_textGroupType;
};

#endif // __XmlParseLangText_h__
