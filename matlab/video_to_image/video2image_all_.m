

clc;
clear;
%% 读取视频  %
temp='test2';
video_path=strcat(temp,'\','video\');
file=dir(video_path);

new_folder=[temp,'\','eachFrame'];
% marked_folder=strcat(new_folder,'marked');
% unmark_folder=strcat(new_folder,'unmark');

if ~exist(new_folder)
      mkdir(new_folder);
end
    
% if ~exist(unmark_folder)
%       mkdir(unmark_folder);
% end

% video_path='G:\mydocuments\Matlab\';
for i=3:numel(file)
    name_length=length(file(i).name);
    filename_postfix=file(i).name(name_length-2:name_length);
    filename_ex=file(i).name(1:name_length-3);
    value=strcmpi(filename_postfix,'mp4');
    if value==1
       video=VideoReader([video_path,file(i).name],'tag', 'myreader1');
      % frame_number=floor(video.Duration * video.FrameRate);计算不准
       numFrames = get(video, 'NumberOfFrames');
%% 创建文件夹
  
       picture_folder=strcat(new_folder,'\',file(i).name(1:name_length-4));

%test = fopen(new_folder)
       if ~exist(picture_folder,'file')
           mkdir(picture_folder);
       end

%% 分离图片
       main_name=file(i).name(1:name_length-4);
       main_name=[picture_folder,'\',main_name];
       for j=1:numFrames
           image_name=strcat(main_name,'_',num2str(j,'%03d'));
           image_name=strcat(image_name,'.jpg');
           I=read(video,j);                               %读出图片
           imwrite(I,image_name,'jpg');                   %写图片
           I=[];
       end
    end
 end
