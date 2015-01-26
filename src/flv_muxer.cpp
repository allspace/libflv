
typedef void* flv_io_handle;
typedef struct
{
    flv_io_handle (*open)(char *name, void *param);
	int (*write)(flv_io_handle handle, char *buff, int len);
	int (*close)(flv_io_handle handle);
}flv_io_writer;

int flv_muxer_open(void *param)
{

}

int flv_muxer_write_header()
{

}

int flv_muxer_write_video()
{

}

int flv_muxer_write_audio()
{

}

int flv_muxer_close()
{

}
