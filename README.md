# muselog

## Introduce
Linux only. C99/C++ library. Simple client for syslog-ng. Easy to write flexible and strong config because for syslog-ng. Wrapper for syslog api. Four api contain.

## Quick start
	
	$ [dnf] or [yum] install syslog-ng.x86_64
	$ cp conf.d/muse.conf /etc/syslog-ng/conf.d
	$ service syslog-ng stop
	$ service syslog-ng start
	$ make [lib] or [example]

## About syslog-ng
Opening muse.conf. You  can see this code.
	
	template t_muse {
    	template("${S_DATE} musefs ${PROGRAM}[${PID}]: [${LEVEL}] ${MSG}\n"); template_escape(no);
	};

Template is the place you define your message format.

I use the next format because I can open it at vim and run filetype=messages to see more color.

	[date] [name] [program[pid]]: [message]



[**For more detail. Click here for opening syslog-ng guide.**](https://www.balabit.com/sites/default/files/documents/syslog-ng-ose-3.4-guides/en/syslog-ng-ose-v3.4-guide-admin/html-single/index.html)

## API
Just have four api.

	bool log_start(Muselog *log, const char *logname, int facility);
	bool flog(Muselog *log, int level, const char *fmt, ...);
	bool vlog(Muselog *log, int level, const char *fmt, va_list ap);
	bool log_move(Muselog *log, const char *save, int size);

### log_start
Two previous params is easy to understand. **logname** normally save under /var/log. **facility** argument is used to specify what type of program is logging the message. This lib use LOCAL 1~7 to save user-define log. 

At muse.conf, you can see this code.

	destination d_muse	{ file("/var/log/muse" template(t_muse)); };
	filter 		f_muse  { facility(local1); };

local1 facility save message at /var/log/muse.
So, it means, one facility bind to one file and just seven facility you can use.

### flog and vlog
flog and vlog is thread-safe, because of syslog-ng. And **level** defined at muselog.h.

### log_move
No thread-safe. Move your log to the path you want to save and truncate the old log. If you don't want to truncate the old file, put **size** = -1.

## Last
Hope you enjoy!


	