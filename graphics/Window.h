/*
 * Window.h
 *
 *  Created on: Jun 27, 2013
 *      Author: nicholaskell
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>
#include "system/Clock.h"

typedef void (*IdleFunction)(void);
typedef void (*DisplayFunction)(void);
typedef void (*ReshapeFunction)(int width, int height);

typedef void (*KeyboardFunction)(unsigned char key, int x, int y);
typedef void (*MouseFunction)(int button, int state, int x, int y);
typedef void (*MotionFunction)(int x, int y);
typedef void (*PassiveMotionFunction)(int x, int y);
typedef void (*EntryFunction)(int state);
typedef void (*VisibilityFunction)(int state);



namespace gal {

    class Window {
        public:
            Window(int argc, char **argv);
            virtual ~Window();
            int getNumberOfWindows() const;
            bool isFullscreen() const;
            void setFullscreen(bool fullscreen);
            int getHeight() const;
            const std::string& getTitle() const;
            void setTitle(const std::string& title);
            int getWidth() const;
            void close();
            void create();
            virtual void* runMainLoop(void*);
            virtual void initOpenGL();
            int getWindowNumber() const;
            int getCurrentFps() const;

            DisplayFunction getDisplayFunction() const;
            EntryFunction getEntryFunction() const;
            IdleFunction getIdleFunction() const;
            KeyboardFunction getKeyboardFunction() const;
            MotionFunction getMotionFunction() const;
            MouseFunction getMouseFunction() const;
            ReshapeFunction getReshapeFunction() const;
            VisibilityFunction getVisibilityFunction() const;
            PassiveMotionFunction getPassiveMotionFunction() const;

            void setDisplayFunction(DisplayFunction displayFunction);
            void setEntryFunction(EntryFunction entryFunction);
            void setIdleFunction(IdleFunction idleFunction);
            void setKeyboardFunction(KeyboardFunction keyboardFunction);
            void setMotionFunction(MotionFunction motionFunction);
            void setMouseFunction(MouseFunction mouseFunction);
            void setPassiveMotionFunction(
                    PassiveMotionFunction passiveMotionFunction);
            void setReshapeFunction(ReshapeFunction reshapeFunction);
            void setVisibilityFunction(VisibilityFunction visibilityFunction);



        protected:
            static IdleFunction idleFunction;
            static DisplayFunction displayFunction;
            static ReshapeFunction reshapeFunction;
            static KeyboardFunction keyboardFunction;
            static MouseFunction mouseFunction;
            static MotionFunction motionFunction;
            static PassiveMotionFunction passiveMotionFunction;
            static EntryFunction entryFunction;
            static VisibilityFunction visibilityFunction;

            static int numberOfWindows;
            int width, height;
            std::string title;
            bool fullscreen;
            int windowNumber;
            static int currentFPS;
            static int frameCount;
            static Time minimumTimeBetweenDraw;
            static Time maximumTimeBetweenDraw;
            static Clock lastDraw;
            static Clock fpsClock;
            void reshape();
            void setCurrentFps(int currentFps);
            void setHeight(int height);
            void setWidth(int width);

            static void defaultIdleMethod();
            static void defaultDisplayMethod();
            static void defaultReshapeMethod(int width,int height);
            static void defaultKeyboardMethod(unsigned char key, int x, int y);
            static void defaultMouseMethod(int button, int state, int x, int y);
            static void defaultMotionMethod(int x, int y);
            static void defaultPassiveMotionMethod(int x, int y);
            static void defaultEntryMethod(int state);
            static void defaultVisibilityMethod(int state);
    };

} /* namespace gal */
#endif /* WINDOW_H_ */
