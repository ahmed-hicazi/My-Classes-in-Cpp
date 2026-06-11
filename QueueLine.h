#pragma once

#include <queue>
#include "clsDate.h"
#include <iostream>

using namespace std;

class QueueLine
{
	class clsTicket
	{
	private:

		short _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients=0;
		short _AverageServeTime=0;
		short _EpectedServeTime = 0;

	public:

		clsTicket(string Prefix, short Number, short WaitingClients
			, short AverageServeTime)
		{
			_Number = Number;
			_TicketTime = clsDate::GetSystemDateAndTime();
			_Prefix = Prefix;
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		}

		string Prefix()
		{
			return _Prefix;
		}

		short Number()
		{
			
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}

	};

	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix="";


public:

	queue <clsTicket> qQueueLine;


	QueueLine(string prefix, short AverageServeTime)
	{
		_Prefix = prefix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(),
			_AverageServeTime);
		qQueueLine.push(Ticket);
	}

	int WaitingClients()
	{
		return qQueueLine.size();
	}

	string WhoIsNext()
	{
		if (qQueueLine.empty())
			return "No Clients Left.";
		else
			return qQueueLine.front().FullNumber();
	}

	bool ServeNextClient()
	{
		if (qQueueLine.empty())
			return false;

		qQueueLine.pop();
		return true;
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}


	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}

	void PrintTicketsLineRTL()
	{
		if (qQueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets:";

		queue <clsTicket> TempQueueLine = qQueueLine;
		clsTicket Ticket("",0,0,0);
		while (!TempQueueLine.empty())
		{
			Ticket = TempQueueLine.front();
			cout << ' ' << Ticket.FullNumber() << " <-- ";
			TempQueueLine.pop();
		}
		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		if (qQueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets:";

		queue <clsTicket> TempQueueLine = qQueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		clsTicket Ticket("",0,0,0);
		while (!TempStackLine.empty())
		{
			Ticket = TempStackLine.top();
			cout << " " << Ticket.FullNumber() << " <-- ";
			TempStackLine.pop();
		}
		cout << "\n";
	}

	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t      ---Tickets---";

		if (qQueueLine.empty())
			cout << "\n\n\t\t\t  ---No Tickets---\n";
		
		queue <clsTicket> TempQueueLine = qQueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}


};

