open Cocoa;

let () = {
  let app = Lazy.force(NSApplication.app);
  let f = () => {
    let w = NSWindow.windowWithContentRect(0, (0., 0., 400., 400.));
    let i = ref(0);
    let f = () => {
      log("Window Did Resize");
      incr(i);
      Printf.ksprintf(NSWindow.setTitle(w), "Resized %d times", i^);
    };
    NSWindow.windowDidResize(f);
    NSWindow.center(w);
    NSWindow.makeKeyAndOrderFront(w);
    let a = NSView.make((0., 0., 400., 400.));
    let b = NSView.make((0., 0., 200., 200.));
    NSView.addSubview(a, b);
    NSWindow.addSubview(w, a);
  };
  app#applicationWillFinishLaunching(f);
  app#run;
};