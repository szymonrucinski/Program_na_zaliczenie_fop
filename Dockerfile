FROM alpine
COPY ["main.cpp","wizytowka.txt","./home/"] 

#RUN AND COMPILE
RUN apk update
RUN apk add  git 
RUN apk add build-base
RUN cd ./home
RUN g++ -o ./home/build ./home/main.cpp
RUN chmod a+x ./home/build
ENTRYPOINT cd ./home && ./build
