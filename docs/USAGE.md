# Usage guide

## Current workflow

1. Start the Windows Forms application from Visual Studio.
2. Choose Open Image.
3. Select a local image in the file dialog.
4. The selected file is loaded with System.Drawing and shown in the PictureBox.

After a successful load, the Open Image button is disabled for that form instance. Restart the application to choose another image.

## Current scope

This is an image-loading prototype. The repository does not currently implement:

- filters, enhancement, cropping, or export;
- multiple-image selection;
- cross-platform support; or
- automated tests.

The application opens a local file, so use only image data that may be viewed on the development machine.
